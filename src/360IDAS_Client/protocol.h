//协议文件
#ifndef PROTOCOL_H
#define PROTOCOL_H

//包头
typedef struct head_t
{
    int type;       //业务类型
    int length;     //业务长度
    unsigned int CRCnum;        //CRC校验码
}HEAD;

//登录请求包
typedef struct login_t
{
    char id[10];    //账号
    char pwd[40];   //密码，MD5加密过
}LOGT;

//注册请求包
typedef struct reg_t
{
    char id[10];    //帐号
    char name[30];  //昵称（中英文和数字）
    char pwd[40];   //密码，MD5加密
}REGT;

//登录 注册返回包
typedef struct backmsg_t
{
    int flag;       //标志　0-成功 1-失败 2-CRC校验错误
    char name[30];  //昵称
    int user_id;    //用户在数据库中的主键ID
}BACKMSGT;

typedef struct video_t
{
    int framenum;//视频总帧数
    int currentframe;//视频当前帧/上次观看帧数
    int equipment_id;//设备id
    int user_id;//用户id
    char video_name[40];//视频名称
    char video_cover[50];//视频封面路径
    char video_path[50];//视频路径
}VIDEOT;

typedef struct serch_t//查询请求包
{
    int equipment_id;//设备id
    int currentPage;//当前页
    int user_id;//用户账号
}SEARCHT;

typedef struct serchrespond_t//查询返回包
{
    int num;//视频个数
    VIDEOT videoarr[4];//视频结构体数组
}SEARCHREST;

typedef struct image_t
{
    char data[1000];//图片数据
    int img_num;//单个图片序号
    int img_length;//单个图片长度
    int img_allBytes;//文件总字节数
    int img_allNums;//零碎文件个数
    char img_name[40];//图片名称
    int img_type;//图片类型 0-行车　１－红绿灯　２－手动
    int user_id;//用户id
    int equipment_id;//设备id
    char img_path[50];//图片路径
}IMAGET;

typedef struct imageOK_t
{
    char img_name[40];//图片名称
    int img_type;//图片类型
    int user_id;//用户id
}IMAGEOKT;

typedef struct imageback_t//图片拼合完成返回包
{
    int flag;//0 拼合完成  1 数据包丢失
    char img_name[50];//图片路径
    char img_nums[100];//所有丢失包的序号
    int user_id;//用户id
}IMAGEBACKT;

typedef struct imageserch_t
{
    int iamge_type;//图片类型
    char image_name[40];//图片名称
    char image_path[50];//图片路径
}IMAGESERCHT;

typedef struct imageserchRespond_t
{
    int image_num;
    IMAGESERCHT image_arr[4];//图片信息数组
}IMAGESERCHREST;


#endif // PROTOCOL_H
