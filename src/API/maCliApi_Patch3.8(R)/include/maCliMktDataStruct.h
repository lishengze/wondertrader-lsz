#if !defined(__MA_CLI_MKT_DATA_STRUCT_H__)
#define __MA_CLI_MKT_DATA_STRUCT_H__

#include "maCliTradeApi.h"

#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
  #if defined(MA_CLIAPI_EXPORTS)
    #define MACLIAPI __declspec(dllexport)
  #else
    #define MACLIAPI __declspec(dllimport)
  #endif
  #define MACLI_STDCALL __stdcall
  #define MACLI_EXPORTS __declspec(dllexport)
#else
  #define MACLIAPI
  #define MACLI_STDCALL
  #define MACLI_EXPORTS
#endif

BGN_NAMESPACE_MACLI

// ����ط�
struct MACLIAPI CReqPlayBackField
{
  char chPlayCtrl;        //���ſ���  PLAY_CTRL CHAR(1) ��  9080  ��0����ֹͣ���� ��1������ʼ����
  char szTrdDate[8+1];    //TRD_DATE              8844
  int  iBgnTime;          //BGN_TIME              916
  int  iEndTime;          //END_TIME              917
  char chPlayBackType;    //PLAY_BACK_TYPE        8996
  int  iPlayInterval;     //�ط�ʱ����  PLAY_INTERVAL INTEGER X 9081  ���ŵ�λ����ʱ���ļ��ʱ��(PLAY_INTERVAL�Ժ���Ϊ��λ)
  char szStkCode[128+1];  //��Ʊ����  STK_CODE  VARCHAR(128)  X 48  ������������ö��ţ������ָ��000001,000002,000003��.
};

struct MACLIAPI CRspPlayBackField
{
};

//��ѡ�ɱ༭
struct MACLIAPI CReqMktDataPortfolioField
{
  char     szUserCode[16+1]; //�û����� USER_CODE VARCHAR(16) Y 8902 cos�û�����
  char     chStkex;          //������   STKEX     CHAR(1)     Y 207
  char     szStkbd[2+1];     //���     STKBD     CHAR(2)     Y 625
  char     szTrdCodes[512+1];//Ʒ�ִ��� TRD_CODES VARCHAR(512)X 48  ���߷ָ�(������ӻ�ɾ��ʱ�ش�)
  char     chOperType;       //�������� OPER_TYPE CHAR(1)     Y 8844;0:��ӣ�1:����ɾ����2:��Χɾ��������Ϊ��������
  char     szBegCode[8+1];   //��ʼ���� BEG_CODE  VARCHAR(8)  X 9000��Χɾ��ʱ�ش�(�˷�Χ������ʼ����ͽ������뱾��)
  char     szEndCode[8+1];   //�������� END_CODE  VARCHAR(8)  X 9001��Χɾ��ʱ�ش�
};

struct MACLIAPI CRspMktDataPortfolioField
{
  int      iAmount;          //����AMOUNTINTEGER8900���ز����ɾ��������
};

//��ѡ�ɲ�ѯ
struct MACLIAPI CReqMktDataPortfolioInfoField
{
  char     szUserCode[16+1]; //�û����� USER_CODE  VARCHAR(16) Y 8902 cos�û�����
  char     chStkex;         //������    STKEX      CHAR(1)     Y 207
  char     szStkbd[2+1];    //���      STKBD      CHAR(2)     Y 625
  char     chQueryFlag;     //��ѯ��ʽ  QUERY_FLAG CHAR(1)     Y 9080;0����λ������ѯ1����λ����ǰ��ѯ2������Χ��ѯ������������
  char     szStkCode[8+1];  //��ѯλ��  STK_CODE   VARCHAR(8)  X 8991��λ�ò�ѯʱ�ش�
  int      iQueryNum;       //��ѯ����  QUERY_NUM  INTEGER     X 8992��λ�ò�ѯʱ�ش������1000��
  char     szBegCode[8+1];  //��ʼ����  BEG_CODE   VARCHAR(8)  X 9000��Χ��ѯʱ�ش�(�˷�Χ������ʼ����ͽ������뱾��)
  char     szEndCode[8+1];  //��������  END_CODE   VARCHAR(8)  X 9001��Χ��ѯʱ�ش�
};

struct MACLIAPI CRspMktDataPortfolioInfoField
{
  char     szUserCode[16+1]; //�û����� USER_CODE   VARCHAR(16)   8902 cos�û�����
  char     chStkex;           //������   STKEX      CHAR(1)       207
  char     szStkbd[2+1];      //���    STKBD       CHAR(2)       625
  int      iAmount;           //����    AMOUNT      INTEGER       8900
  char     szStkCodes[1536+1];//����(����)STK_CODES VARCHAR(512)  48  |�ָ�������
};

//-------------------------------10388210:k����ʷ����--------------------------
struct MACLIAPI CReqMktDataKDataField
{
  char            chMarket;                   // �г� 
  char            szCode[8 + 1];              // ���� 
  char            chCqFlag;                   // ��Ȩ��־ 0������Ȩ����֧�֣� 1����ǰ��Ȩ�����������ȥ�� 2�����Ȩ���ӹ�ȥ�����ڣ�
  int             iCqDate;                    // ��Ȩ���� ���㸴Ȩ����,Ĭ�ϵ�ǰ����
  char            chQjFlag;                   // ȫ�۱�־ 0:���ۣ�1��ȫ��
  char            szCycType[2 + 1];           // �������� 0���루��֧�֣� 1���� 2���� 3���� 4���� 5���� 6������ 7���� 8��tickbar����֧�֣� 9��5�� 10��15�� 11��30�� 12��60��
  int             iCycDef;                    // �������� 0 ������
  char            chAutoComplete;             // �Զ����� 0�������� ��������
  int             iBegDate;                   // ��ʼ���� 
  int             iEndDate;                   // �������� 
  int             iBegTime;                   // ��ʼʱ�� ���߼����ϷǱ���
  int             iEndTime;                   // ����ʱ�� ���߼����ϷǱ���
  char            chOrder;                    // ����˳�� ��0Ϊ���� ����Ϊ˳��
  int             iNodeId;                    // �ڵ�ID �ڲ�ʹ��
};

struct MACLIAPI CRspMktDataKDataField
{
  char            chMarket;                   // �г� 
  char            szCode[8 + 1];              // ���� 
  int             iAmount;                    // ���� ��������
  int             iBegDate;                   // ��ʼ���� 
  int             iEndDate;                   // �������� 
  int             iBegTime;                   // ��ʼʱ�� �ա��ܡ��¡��������ꡢ����û�п�ʼ������ʱ��
  int             iEndTime;                   // ����ʱ�� 
  LONGLONG        llMarktDataTime;            // ����ʱ�� ��ѯʱ������tick����ʱ��
  LONGLONG        llMatchedVol;               // �ɽ����� ��ѯʱ������tick�ɽ�����
  LONGLONG        llMatchedAmtTot;            // �ɽ��ܽ�� ��ѯʱ������tick�ɽ��ܽ��
  char            szData[256000 + 1];         // ���� {����|ʱ��|���̼�|���|���|���̼�|�ɽ���|�ɽ��ܽ��/�ֲ���|��Ȩ��Ϣ��|����/���}{}... ���У�����YYYYMMDD ʱ��HHMMSSmmm �۸���Ϊʵ�ʼ۸�10000�� �ֻ�Ϊ��ᡢ�ɽ��ܽ�� ��Ȩ�ڻ�Ϊ��ᡢ�ֲ��� ���Ϊ�� {����|ʱ��|����|����|�ɽ���|�ֲ�����|�ɽ�����|�ɽ���|�ɽ����|iopv} ���ͣ� '0' �໻ '1' �ջ� '2' ˫�� '3' �࿪ '4' �տ� '5' ˫�� '6' ��ƽ '7' ��ƽ '8' ˫ƽ ���� 0:�� 1:�� ����: ��Ʊֻ�У�0��1��2��
};

//tick����
struct MACLIAPI CReqMktDataTickSnapshotField
{
  char     chStkex;          //������    STKEX     CHAR(1)     Y 8899
  char     szStkCodes[512+1];//����(����)STK_CODES VARCHAR(512)Y 8900 |�ָ��ֻ����,���֧�ֵ���40ֻ���룬����40ֻ�����ಿ�ֲ��ٴ���
};

struct MACLIAPI CRspMktDataTickSnapshotField
{
  char     chStkex;       //������STKEX CHAR(1)         8899
  int      iAmount;       //����  AMOUNTINTEGER         8901���ص���������
  char     szData[40960+1];//���� DATA  VARCHAR(40960)  8902{..|..|..}{..|..|..}...���У�����YYYYMMDDʱ��HHMMSSmmm�۸���Ϊʵ�ʼ۸�10000��,�����������ʽΪST_MKT_DATA�ṹ���ֶ�
};

//ǧ�������ѯ
struct MACLIAPI CReqMktDataThounsandDataField
{
  char     chStkex;           // ������     STKEX         CHAR(1)       ��  8899
  char     szStkCodes[512+1]; // ����(����) STK_CODES     VARCHAR(512)  ��  8900  |�ָ��ֻ����
  int      iCategory;         // ���׷���   STK_CATEGORY  INTEGER       ��  625  
};

struct MACLIAPI CRspMktDataThounsandDataField
{
  char     chStkex;           // ������ STKEX    CHAR(1)       8899
  int      iAmount;           // ����	 AMOUNT	INTEGER	        8901	���ص���������
  char     szData[2048 + 1];  // ����   DATA     VARCHAR(2048) 8902
};

//-------------------------------10388226:ָ����ֵ��ѯ--------------------------
struct MATRADEAPI CReqMktDataQryIndexValField
{
  char            szCode[16 + 1];             // ���� ָ������
  int             iDate;                      // ���� ��������(��ʽ:20210720)
};

struct MATRADEAPI CRspMktDataQryIndexValField
{
  char            szData[512 + 1];            // ���� ���� ��ʽ: indexcode|indexname|trd_date|pe|pepercentiles|pb|pbpercentiles|ispe ʾ��: SZ399814|��ũҵ|20210715|27.1828|20.8578|4.9515|87.074|1 
};

//-------------------------------10388232:��ָ���������--------------------------
struct MATRADEAPI CReqMktDataQryCloudIndexField
{
  char            chMarket;                   // �г� 
  char            szCode[8 + 1];              // ���� 
  char            chCqFlag;                   // ��Ȩ��־ 0������Ȩ 1����ǰ��Ȩ�����������ȥ�� 2�����Ȩ���ӹ�ȥ�����ڣ�
  int             iCqDate;                    // ��Ȩ���� ���㸴Ȩ����,Ĭ�ϵ�ǰ����
  char            chQjFlag;                   // ȫ�۱�־ ��֧��
  char            szCycType[2 + 1];           // �������� 0���� 1���� 2���� 3���� 4���� 5���� 6������ 7���� 9��5�� 10��15�� 11��30�� 12��60�� 13:3�� 14��5�� 15��10�� 16��15�� 17��20�� 18��30��
  int             iCycDef;                    // �������� 0 ������
  char            chAutoComplete;             // �Զ����� ��֧��
  int             iBegDate;                   // ��ʼ���� 
  int             iEndDate;                   // �������� 
  int             iBegTime;                   // ��ʼʱ�� ���߼����ϷǱ���
  int             iEndTime;                   // ����ʱ�� ���߼����ϷǱ���
  char            chOrder;                    // ����˳�� ��0Ϊ���� ����Ϊ˳��
  char            szName[20 + 1];             // ָ������ ָ������,��Сд����
  char            szParams[20 + 1];           // ָ����� ָ�����,�����,ʹ��Ĭ�ϲ�������ָ��,�ǿ��򰴴���Ĳ���ֵ����,��������ԡ�~���ָ�,ʾ��: ��100~200~300��
  int             iVolunit;                   // �ɽ������� ���������
};

struct MATRADEAPI CRspMktDataQryCloudIndexField
{
  char            chMarket;                   // �г� 
  char            szCode[8 + 1];              // ���� 
  int             iAmount;                    // ���� ��������
  int             iBegDate;                   // ��ʼ���� 
  int             iEndDate;                   // �������� 
  int             iBegTime;                   // ��ʼʱ�� �ա��ܡ��¡��������ꡢ����û�п�ʼ������ʱ��
  int             iEndTime;                   // ����ʱ�� 
  char            szName[20 + 1];             // ָ������ ָ������
  char            szData[256000 + 1];         // ���� // �ȷ�������ָ���ߵ�����,����,����,��ɫ������ ָ����1: ����,ָ��������,ָ������չ����,��������,���ʹֶ�,ָ������ɫ,�������ݸ���,������������| ָ����2: ����,ָ��������,ָ������չ����,��������,���ʹֶ�,ָ������ɫ,�������ݸ���,������������| ָ����N: ����,ָ��������,ָ������չ����,��������,���ʹֶ�,ָ������ɫ,�������ݸ���,������������| ������: "~" // �ٷ��ؾ����ָ����ֵ����, �ӵ�һ��ʱ��㵽���һ��ʱ���(��������K �߸���), ÿһ��ʱ����Ӧһ�� ST_MKT_INDEX�ṹ�屣����������, ����DeSerialize() �⿪ ÿ��ʱ�������֮��ķָ��� "~"
};

END_NAMESPACE_MACLI

#endif  //__MA_CLI_MKT_DATA_STRUCT_H__