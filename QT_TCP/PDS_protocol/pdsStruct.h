#ifndef PDSSTRUCT_H
#define PDSSTRUCT_H
#include <cstdint>
<<<<<<< HEAD
#include<QByteArray>
=======

#pragma pack(1)     //设置结构体为1字节对齐
>>>>>>> 78ebb0cbbff571e6e64c151d822248aaabf1fcb2
typedef struct
{
                                   //total: 25 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 1,The command id of the request being sent)
    uint32_t argsLen;              //4 byte  (value: 7,The size in bytes of the arguments sent to the command)
    uint16_t palletType;           //2 byte  (value: 1 = CHEP_FRONT, 2=CHEP_SIDE,3=GMA, 4=BLOCK, 5=STRINGER,6=COMPOSED_BLOCK*)
    float    depthHint;            //4 byte  (Depth hint from front of camera glass in meters)
    uint8_t  filterMask;           //1 byte  (bit0 = stray light filter, bit1 = fast flying pixel filter, bit2 = stretch wrap filter)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getPalletRequest;
#pragma pack()		//结束结构体对齐设置

typedef struct
{
                                   //total: 78 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 1,The command id of the request being sent)
    uint32_t errorCode;            //4 byte  (Unless the return code is PDS_NO_ERRORS, the caller should not attempt the pick)
    uint32_t len;                  //4 byte  (value: 62:56+6,length in bytes of “payload” + “stop sequence)
    float    elapsedTime;          //4 byte  (Elapsed time (sec) of the detection)
    float    confidence;           //4 byte  (Average correlation score of the segmented pallet pockets against the pocket-type kernel.)
    float    palletX;              //4 byte  (X-position of pallet in camera frame(meters))
    float    palletY;              //4 byte  (Y-position of pallet in camera frame(meters))
    float    palletZ;              //4 byte  (Z-position of pallet in camera frame(meters))
    float    leftPocketX;          //4 byte  (X-position of left pocket in camera frame(meters))
    float    leftPocketY;          //4 byte  (Y-position of left pocket in camera frame(meters))
    float    leftPocketZ;          //4 byte  (Z-position of left pocket in camera frame(meters))
    float    rightPocketX;         //4 byte  (X-position of right pocket in camera frame(meters))
    float    rightPocketY;         //4 byte  (Y-position of right pocket in camera frame(meters))
    float    rightPocketZ;         //4 byte  (Z-position of right pocket in camera frame(meters))
    float    roll;                 //4 byte  (Rotation of pallet about the x-axis in the camera frame (radians))
    float    pitch;                //4 byte  (Rotation of pallet about the y-axis in the camera frame (radians))
    float    yaw;                  //4 byte  (Rotation of pallet about the z-axis in camera frame (radians))
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getPalletResponse_success;

typedef struct
{
                                   //total: 22 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 1,The command id of the request being sent)
    int32_t errorCode;            //4 byte  (value: Unless the return code is PDS_NO_ERRORS, the caller should not attempt the pick)
    uint32_t len;                  //4 byte  (value: 6,length in bytes of “payload” + “stop sequence)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getPalletResponse_failure;


<<<<<<< HEAD
typedef struct 
{
    //total 22 bytes
    char startSequence[4];         //4 bytes (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 2,The command id of the request being sent)
    uint32_t argsLen;              //4 byte  (value: 4,The size in bytes of the arguments sent to the command)
    uint32_t arrayID;              //4 byte  (search reference in PDS.md)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getArrayRequest;

typedef  struct
{
    //total 46 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 2,The command id of the request being sent)
    int32_t errorCode;            //4 byte  (Unless the return code is PDS_NO_ERRORS, the caller should not attempt the pick)
    uint32_t len;                  //4 byte  (value: 6+(payload),length in bytes of “payload” + “stop sequence)
    int32_t rows;                  //4 byte  rows of the data
    int32_t columns;               //4 byte  columns of the data
    int32_t channels;              //4 byte channels of the data
    int32_t pixelType;             //4 byte data type of the pixel
    void* pixel;                   //8 bytes (point to a 64 bit address of the pixel data,remember to cast it to proper type before use it) or you can use it as a byte array
    //pixel need to change
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getArrayResponse_success;


typedef  struct
{
    //total: 22 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 2,The command id of the request being sent)
    int32_t errorCode;            //4 byte  (value: Unless the return code is PDS_NO_ERRORS, the caller should not attempt the pick)
    uint32_t len;                  //4 byte  (value: 6,length in bytes of “payload” + “stop sequence)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))

}getArrayResponse_failure;

typedef  struct
{
    //total 18 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 3,The command id of the request being sent)
    uint32_t argsLen;              //4 byte  (value: 0,The size in bytes of the arguments sent to the command)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}saveReferenceForkRequest;

typedef  struct
{
    //total: 22 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 3,The command id of the request being sent)
    int32_t errorCode;            //4 byte  (value: Unless the return code is PDS_NO_ERRORS, the caller should not attempt the pick)
    uint32_t len;                  //4 byte  (value: 6,length in bytes of “payload” + “stop sequence)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))

}saveReferenceForkResponse;

typedef  struct
{
    //total 42 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 4,The command id of the request being sent)
    uint32_t argsLen;              //4 byte  (value: 24,The size in bytes of the arguments sent to the command)
    uint8_t horizontalDropPos;      //1 byte  (0 left 1 middle 2 right)
    uint8_t verticalDropPos;        //1 byte (0 top 1 inside 2 botton rail 3 floor)
    uint8_t cameraPos;              //1 byte (0 full up 1 full down)
    float depthHint;                //4 byte  (distance from rack to camera glass)
    float zHint;                    //4 byte (Estimated z-coord of rack shelf in camera frame (meters))
    float clearingDepth;           //4 byte (distance free of obstacle in the +x direction)
    float clearingWidth;           //4 byte (distance free of obstacle in the x direction,left is - ,right is +)
    float clearingHeight;          //4 byte (distance free of obstacle in the +z direction)
    uint8_t strayLightFilter;       //4 byte (0 not use// 1 use)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getRackRequest;

typedef  struct
{
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 4,The command id of the request being sent)
    int32_t errorCode;            //4 byte  (value: Unless the return code is PDS_NO_ERRORS, the caller should not attempt the pick)
    uint32_t len;                  //4 byte  (value: 6+payload,length in bytes of “payload” + “stop sequence)
    float elapseTime;              //4 byte  (time use to detect)
    float confidence;               //4 byte (Currently Unused)
    float   X;                      //4 byte (rack x position in camera frame)
    float   Y;                      //4 byte (rack y position in camera frame)
    float   Z;                      //4 byte (rack z position in camera frame)
    float   roll;                   //4 byte (Rotation of rack about x-axis (radians))
    float   pitch;                  //4 byte (Rotation of rack about y-axis (radians))
    float   yaw;                    //4 byte (Rotation of rack about z-axis (radians))
    uint8_t side;                   //1 byte (0 left 1 middle(usually not happen) 2 right)
    uint32_t flag;                  //4 byte (detail are belows)
    //0 NO_BEAM The horizontal beam of the rack grid location could not be segmented (this is a “hard” error)
    //1 MULTIPLE_BEAMS Multiple horizontal beam candidates were segmented, the “best” (the top) one was selected
    //2 BEAM_COVERAGE A threshold of pixel coverage over the surface area of the beam was not met
    //3 NO_UPRIGHT A vertical upright was not detected, the rack frame was established based on the segmented beam, sweeping volume, and (optionally) the floor
    //4 MULTIPLE_UPRIGHTS Multiple upright candidates (on the anchor side of interest) were segmented, the “best” (most interior) one was detected
    //5 UPRIGHT_COVERAGE A threshold of pixel coverage over the surface area of the upright was not met
    //6 NO_JOIN The beam and the upright used to establish the rack frame do not intersect in the point cloud
    //7 BAD_TRANSFORM The origin of the computed rack frame is outside of an expected tolerance (indicative of a beam-only localization anchoring to an obstacle)
    //8 SHELF_OBSTACLE An obstacle was detected within the shelf sweeping volume with respect to the established rack frame
    //9 BAD_SHELF_LIMITS The user-supplied clearing volume parameters were invalid and the default values (those in the config file) were used to detect obstacles
    //10 … 31 RESERVED
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getRackResponse_success;

typedef  struct
{
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 4,The command id of the request being sent)
    int32_t errorCode;             //4 byte  (value: Unless the return code is PDS_NO_ERRORS, the caller should not attempt the pick)
    uint32_t len;                  //4 byte  (value: 6)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getRackResponse_failure;


typedef  struct
{
    //total 42 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 5,The command id of the request being sent)
    uint32_t argsLen;              //4 byte  (value: 25,The size in bytes of the arguments sent to the command)
    float   xmin;                  //4 byte  (Min x in VOI (meters, camera frame))
    float   xmax;                  //4 byte  (Max x in VOI (meters, camera frame))
    float   ymin;                  //4 byte  (Min y in VOI (meters, camera frame))
    float   ymax;                  //4 byte  (Max y in VOI (meters, camera frame))
    float   zmin;                  //4 byte  (Min z in VOI (meters, camera frame))
    float   zmax;                  //4 byte  (Max z in VOI (meters, camera frame))
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}volCheckRequest;

typedef  struct
{
    //total 30 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 5,The command id of the request being sent)
    int32_t errorCode;             //4 byte  (value: Unless the return code is PDS_NO_ERRORS, the caller should not attempt the pick)
    uint32_t len;                  //4 byte  (value: 6)
    float   elapseTime;            //4 byte (Elapsed time to compute the volume)
    int32_t Npix;                  //4 byte (Number of pixels in the VOI)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}volCheckResponse;

typedef struct
{
    //total: 18 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 7,The command id of the request being sent)
    uint32_t argsLen;              //4 byte  (value: 0,The size in bytes of the arguments sent to the command)
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getConfigRequest;


typedef  struct
{
    //total 30 bytes
    char     startSequnce[4];      //4 byte  (The fixed byte string: (115, 116, 97, 114) aka (‘s’, ‘t’, ‘a’, ‘r’))
    uint32_t commandID;            //4 byte  (value: 7,The command id of the request being sent)
    int32_t errorCode;             //4 byte  (value: Unless the return code is PDS_NO_ERRORS, the caller should not attempt the pick)
    uint32_t len;                  //4 byte  (value: 6+payload)
    //config array todo
    void* payload;                 //8 byte  (pointer to )
    char     stopSequence[6];      //6 byte  (The fixed byte string: (115, 116, 111, 112, 13, 10) aka (‘s’, ‘t’, ‘o’, ‘p’, ‘\r’, ‘\n’))
}getConfigResponse;



=======
>>>>>>> 78ebb0cbbff571e6e64c151d822248aaabf1fcb2
#endif // PDSSTRUCT_H
