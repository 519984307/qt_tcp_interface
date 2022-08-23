#include "serverwidget.h"
#include "ui_serverwidget.h"
#include "PDS_protocol/pdsPalletRequestClass.h"
#include "PDS_protocol/pdsPalletResponseClass.h"
#include "PDS_protocol/pdsPalletCoordinateClass.h"

typedef unsigned char byte;


ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    tcpServer = NULL;
    tcpSocket = NULL;

    tcpServer = new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any,55556);  //5678

    setWindowTitle("Server:Port_55556");

    connect(tcpServer,&QTcpServer::newConnection,this,
            [=]()
            {
                tcpSocket = tcpServer->nextPendingConnection();
                QString ip = tcpSocket->peerAddress().toString();
                quint16 port = tcpSocket->peerPort();
                QString temp = QString("[%1:%2]:Connect Successful!").arg(ip).arg(port);
                ui->textEditRead->setText(temp);

                connect(tcpSocket,&QTcpSocket::readyRead,this,
                        [=]()mutable
                        {
                            QByteArray array = tcpSocket->readAll();
                            ui->textEditRead->append(array.toHex());
                            int count = array.count();
                            qDebug("%d",count);
                            if(count==25)
                            {
                                pdsPalletRequestClass palletRequest(array);
                                QString str= "commandID:"+QString::number(palletRequest.palletRequestStruct.commandID) +
                                             " palletType:"+QString::number(palletRequest.palletRequestStruct.palletType)+
                                             " depthHint:"+QString::number(palletRequest.palletRequestStruct.depthHint);
//                                tcpSocket->write(str.toUtf8().data());
                                int errorCode = 0;
                                if(errorCode !=0 )
                                {
                                    pdsPalletResponseClass palletResponse;
                                    palletResponse.response_failure(palletRequest.palletRequestStruct.commandID,errorCode);
                                    QByteArray array;
                                    array = palletResponse.ToFailureArray();
                                    tcpSocket->write(array);
                                }
                                else
                                {
                                    float elapsedTime = 100.1;
                                    float confidence = 200.2;
                                    pds_point centerPoint = {.x=0.1,.y=0.2,.z=0.3};
                                    pds_point leftPoint = {.x=-1.1,.y=-2.2,.z=-3.3};
                                    pds_point rightPoint = {.x=1.1,.y=2.2,.z=3.3};
                                    pds_posture posture = {.roll=0.875,.pitch=0.625,.yaw=-0.375};
                                    pdsPalletCoordinateClass palletCoordinate(
                                                             elapsedTime,
                                                             confidence,
                                                             centerPoint,
                                                             leftPoint,
                                                             rightPoint,
                                                             posture);

                                    pdsPalletResponseClass palletResponse;
                                    palletResponse.response_success(palletCoordinate);
                                    QByteArray array;
                                    array = palletResponse.ToSuccessArray();
                                    tcpSocket->write(array);
                                }
                            }
                        }
                        );

            }
            );
}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_buttonSend_clicked()
{
    if(tcpServer == NULL)
    {
        return;
    }
    QString str= ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
}

void ServerWidget::on_buttonClose_clicked()
{
    if(tcpServer == NULL)
    {
        return;
    }
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpServer = NULL;
}
