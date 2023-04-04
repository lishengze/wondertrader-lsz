//----------------------------------------------------------------------------
// ��Ȩ������������ģ�����ڽ�֤΢�ں˼ܹ�ƽ̨(KMAP)��һ����
//           ��֤�Ƽ��ɷ����޹�˾  ��Ȩ����
//
// �ļ����ƣ�maMktData.h
// ģ�����ƣ�΢�ܹ��ͻ���(Client)������ṹ����
// ģ��������
// �������ߣ������
// �������ڣ�2015-07-17
// ģ��汾��1.3
//----------------------------------------------------------------------------
// �޸�����      �汾          ����            ��ע
//----------------------------------------------------------------------------
// 2015-07-17    1.0          �����          ����
// 2016-03-18    1.0          �߽�            ����ST_MKT_DATA2��ST_MKT_DATA3�ɽ������ɽ�����ֶΣ�
//                                            ���ֿ��ַ���ʱ���޷������л�����д�����л�ʵ��
// 2016-08-16    1.0          �߽�            ST_MKT_DATA2�����������̼ۣ��Լ�4��Ԥ���ֶ�
// 2016-12-16    1.1          �߽�            ����ST_MKT_DATA�ֶε�����
// 2018-03-08    1.2          �߽�            ����ST_MKT_MATCH��ʡ�ST_MKT_ORDERί�нṹ��,ST_MKT_INDEXָ��ṹ��
//                                            ���鶩������DATA_SET���,2(ԭ�����鶩��),8(�ɽ�����),16(ί�ж���),32(ָ�궩��),���Ϊ����ǰ����,���Ķ���ȡֵ�û�
// 2019-02-12    1.3          �Ŷ���          ֧��L2����Դ����
// 2019-09-06    1.4          ������          ST_MKT_DATA2���ӿ��̼�uiOpenPrice������uiReserved1~4��������uiReserved5~8
// 2020-02-28    1.5          ������          ����ָ��ST_MKT_INDEX��uiValues��uiExtra�������ʹ�unsigned int��Ϊunsigned long long
// 2021-05-10    1.6          ���ľ�          �޸�ST_MKT_DATA,ST_MKT_DATA2��ͣ�۵�ͣ�����ʹ�unsigned int��Ϊlong long;
// 2021-12-17    1.7          ���ľ�          �޸�ST_MKT_DATAԤ���ֶ�llReserved���ӵ�10��;
//----------------------------------------------------------------------------
#if !defined(__MA_MKT_DATA_H__)
#define __MA_MKT_DATA_H__

#include <stdio.h>

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

#if defined (_MSC_VER) && (_MSC_VER == 1200)
  #define FORMAT_LONGLONG "%I64d"
  #if defined(WIN32) || defined(WIN64)
  typedef __int64 LONGLONG;
  #endif
#else
  #define FORMAT_LONGLONG "%lld"
  typedef long long LONGLONG;
#endif

#pragma pack(1)
//////////////////////////////////////////////////////////////////////////
// llMktDataTime:����������Ľ���ʱ��,��ʽYYYYMMDDHHMMSSsss
// chExchange   :��������0�Ͻ�����1�����A��������B��������C֣������G�н���
// iTrdDate     :�������ݱ��������,��ʽYYYYMMDD
// iDataTime    :�������ݱ����ʱ��,��ʽHHMMSSsss
// uiMatchedCnt :����,��С������
// szStatus     :Ʒ��״̬
//               '0' δ����
//               'Y' �²�Ʒ
//               'R' ���׼䣬��ֹ�κν��׻
//               'P' ���У����磬������С��޴���г��ڲ���Ϣ��¶��
//               'B' ͣ��
//               'C' ����
//               'D' ͣ��
//               'Z' ��Ʒ��ɾ��
//               'V' ��������
//               'T' �̶��۸񼯺Ͼ���
//               'W' ��ͣ���������ж����ͽ��׵Ĳ�ѯ֮�⣬�κν��׻������ֹ��
//               'X' ͣ��,( 'X'��'W'����������'X'ʱ���Գ���)
//               'I' ���м��Ͼ��ۡ�
//               'L' ���м��Ͼ���PreOBB
//               'I' ���м��Ͼ���
//               'K' ���м��Ͼ��۶�����ƽ��(OBB)ǰ��ʱ��
//               'S' �ǽ��׷���֧��
//               'U' �̺���
//               'F' ��ǰ����
//               'E' ����
//               'O' �������
//               'Q' �������׺ͼ��Ͼ��۵Ĳ������ж�
//               'J' ���̼��Ͼ���
//               'M' �ɻָ������۶�ʱ��(���м��Ͼ���)
//               'N' ���ɻָ����׵��۶�ʱ��(��ͣ����������)
//
// �۸�         :Ԫ,4λС��,ʵ�ʼ۸�10000��
// �����ɽ���   :��ƱΪ����,��Ȩ�ڻ�Ϊ����,����С������
// ���         :Ԫ,��С������
// ��ӯ�ʵ������ֶ�,��ʽ����
//////////////////////////////////////////////////////////////////////////
//��������(����)
struct MACLIAPI ST_MKT_DATA
{
  bool      bInitialized;
  LONGLONG  llMktDataTime;                    // ����ʱ��(YYYYMMDDHHMMSSmmm)
  char      chExchange;                       // ������
  char      szTrdCode[16 + 1];                // Ʒ�ִ���
  int       iTrdDate;                         // ��������
  int       iDataTime;                        // ����ʱ��(HHMMSSmmm)
  char      szStatus[1+1];                    // Ʒ��״̬

  unsigned int    uiPreClosePrice;            // �����̼�
  unsigned int    uiOpenPrice;                // ���̼�
  unsigned int    uiHighPrice;                // ��߼�
  unsigned int    uiLowPrice;                 // ��ͼ�
  unsigned int    uiCurPrice;                 // ���¼�
  unsigned int    uiAnsPrice[10];             // ������
  LONGLONG        llAnsVol[10];               // ������
  unsigned int    uiBidPrice[10];             // �����
  LONGLONG        llBidVol[10];               // ������
  unsigned int    uiMatchedCnt;               // �ɽ�����
  LONGLONG        llMatchedVol;               // �ɽ�����
  LONGLONG        llMatchedAmtTot;            // �ɽ��ܽ��
  LONGLONG        llBidVolTot;                // ��������
  LONGLONG        llAnsVolTot;                // ��������
  unsigned int    uiBidPriceAvg;              // ƽ��ί��۸�
  unsigned int    uiAnsPriceAvg;              // ƽ��ί���۸�
  int             iIopv;                      // IOPV
  int             iYield;                     // ����������
  long long       uiHighLmtPrice;             // ��ͣ��
  long long       uiLowLmtPrice;              // ��ͣ��
  char            szStkPrefix[16 + 1];        // ֤ȯǰ׺
  LONGLONG        llPreOpenVol;               // ��ֲ���
  unsigned int    uiSettPrice;                // ������
  int             iPreDelta;                  // ����ʵ��
  int             iCurrDelta;                 // ����ʵ��
  int             iNsyl1;                     // ��ӯ��1
  int             iNsyl2;                     // ��ӯ��2
  int             iNsd2;                      // ����2
  LONGLONG        llOpenVol;                  // �ֲ�����
  unsigned int    uiPreSettPrice;             // ������
  unsigned int    uiClosePrice;               // ������
  char            szContractID[32 +1];        // ��Ȩ��Լ����
  char            szUnderlyingSecurityID[32]; // ���֤ȯ����
  char            szCallOrPut[1+1];           // �Ϲ��Ϲ�C1
  int             iExerciseDate;              // ��Ȩ��Ȩ�գ�YYYYMMDD
  char            szCallOrPutStatus[1+1];     //

  long long       uiAuctionPrice;             // �Ϻ���̬�ο��۸������۶ϼ۸���Ȩ��
  unsigned long long ullAuctionQty;           // �Ϻ�����ƥ����������Ȩ��
  unsigned long long ullSecuritySwitchType;   // ����֤ȯʵʱ״̬
  char            szTradingPhaseCode[8+1];    // ��Ʒʵʱ�׶μ���־
  long long       llReserved[10];             // Ԥ���ֶ�

  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//��������(����)
struct MACLIAPI ST_MKT_DATA2
{
  bool            bInitialized;
  LONGLONG        llMktDataTime;              // ����ʱ��(YYYYMMDDHHMMSSmmm)
  char            chExchange;                 // ������
  char            szTrdCode[16 + 1];          // Ʒ�ִ���
  int             iTrdDate;                   // ��������
  int             iDataTime;                  // ����ʱ��(HHMMSSmmm)
  char            szStatus[1+1];              // Ʒ��״̬

  unsigned int    uiCurPrice;                 // ���¼ۣ��۸�*10000)
  unsigned int    uiAnsPrice[10];             // �����ۣ��۸�*10000)
  LONGLONG        llAnsVol[10];               // ������
  unsigned int    uiBidPrice[10];             // ����ۣ��۸�*10000)
  LONGLONG        llBidVol[10];               // ������
  unsigned int    uiMatchedCnt;               // �ɽ�����
  LONGLONG        llMatchedVol;               // �ɽ���
  LONGLONG        llMatchedValue;             // �ɽ����

  unsigned int    uiPreClosePrice;            // �����̼�
  unsigned int    uiReserved1;                // ��߼�
  unsigned int    uiReserved2;                // ��ͼ�
  long long       uiReserved3;                // ��ͣ��
  long long       uiReserved4;                // ��ͣ��
  unsigned int    uiReserved5;                // Ԥ��5
  unsigned int    uiReserved6;                // Ԥ��6
  unsigned int    uiReserved7;                // Ԥ��7
  unsigned int    uiReserved8;                // Ԥ��8
  unsigned int    uiOpenPrice;                // ���̼�

  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//��������(Ԥ��)
struct MACLIAPI ST_MKT_DATA3
{
  bool            bInitialized;
  LONGLONG        llMktDataTime;              // ����ʱ��(YYYYMMDDHHMMSSmmm)
  char            chExchange;                 // ������
  char            szTrdCode[16 + 1];          // Ʒ�ִ���
  int             iTrdDate;                   // ��������
  int             iDataTime;                  // ����ʱ��(HHMMSSmmm)
  char            szStatus[1+1];              // Ʒ��״̬

  unsigned int    uiCurPrice;                 // ���¼ۣ��۸�*10000)
  unsigned int    uiAnsPrice[5];              // �����ۣ��۸�*10000)
  LONGLONG        llAnsVol[5];                // ������
  unsigned int    uiBidPrice[5];              // ����ۣ��۸�*10000)
  LONGLONG        llBidVol[5];                // ������
  unsigned int    uiMatchedCnt;               // �ɽ�����
  LONGLONG        llMatchedVol;               // �ɽ���
  LONGLONG        llMatchedValue;             // �ɽ����
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//��ʱ�ɽ�
struct MACLIAPI ST_MKT_MATCH
{
  bool           bInitialized;
  char           chExchange;             // ������
  char           szTrdCode[16 + 1];      // Ʒ�ִ���
  int            iTrdDate;               // ��������
  char           chType;                 // ����:0�໻1�ջ�2˫��;3�࿪4�տ�5˫��;6��ƽ7��ƽ8˫ƽ
  char           chBSSide;               // ��������:0:�� 1:�� ����:
  int            iDataDate;              // ��������
  int            iDataTime;              // ����ʱ��
  int            iIopv;                  // (Indicative Optimized Portfolio Value)ETF�Ļ���ݶ�ο���ֵ,�ɽ�����ÿ15����㲢����һ��,ʵ�ʼ۸�10000��
  unsigned int   uiPrice;                // �ɽ���
  int            iOpenVol;               // �ֲ�����
  unsigned int   uiMatchedCnt;           // �ɽ�����
  unsigned int   uiMatchedVol;           // �ɽ���
  LONGLONG       llMatchedAmtTot;        // �ɽ����
  int            iTimediff;              // ����˱ʳɽ������ʿ���ʱ��� ԽСԽ׼ȷ
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//���ί��
struct MACLIAPI ST_MKT_ORDER
{
  bool           bInitialized;
  char           chExchange;             // ������
  char           szTrdCode[16 + 1];      // Ʒ�ִ���
  int            iTrdDate;               // ��������
  char           chOrderDirection;       // ί�з��� B, S, C
  int            iDataDate;              // ί������
  int            iDataTime;              // ί��ʱ��
  int            iOrderNo;               // ί�к�
  unsigned int   uiOrderPrice;           // ί�м۸�
  int            iOrderVol;              // ί������
  int            iIndex;                 // ί�б�ţ���1��ʼ������1
  char           chOrderKind;            // ί������, 1=�м� 2=�޼� U=��������
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//���10 ��ָ����
#define INDEXLINE_NUM 10

//����ָ��
struct MACLIAPI ST_MKT_INDEX
{
  bool                bInitialized;
  char                chExchange;         // ������
  char                szTrdCode[16 + 1];  // Ʒ�ִ���
  int                 iTrdDate;           // ��������
  int                 iDataDate;          // ָ������
  int                 iDataTime;          // ָ��ʱ��
  int                 iIndexID;           // ָ��ID
  int                 iKLinePeriod;       // K������
  long long           llValues[INDEXLINE_NUM];    // ָ���ߵ�ֵ
  char                szExtra[20*INDEXLINE_NUM+1];// �����õĶ����ַ���
  long long           llExtra[5*INDEXLINE_NUM];   // ���ܵĶ�������
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//ί�ж���
struct MACLIAPI ST_MKT_ORDER_QUEUE
{
  bool           bInitialized;
  char           chExchange;             // ������
  char           szTrdCode[16 + 1];      // Ʒ�ִ���
  int            iTrdDate;               // ��������
  int            iDataDate;              // ί������
  int            iDataTime;              // ί��ʱ��
  int            iSide;                  // ��������
  unsigned int   iPrice;                 // ί�м۸�
  int            iOrderItems;            // �����������õ�λ�ϵ���ί������
  int            iABItems;               // ��ϸ�������õ�λ�Ͻ�ʾ��ί������
  int            iABVolum[256];          // ������ϸ
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//��ʳɽ�
struct MACLIAPI ST_MKT_TRANSACTION
{
  bool           bInitialized;
  char           chExchange;             // ������
  char           szTrdCode[16 + 1];      // Ʒ�ִ���
  int            iTrdDate;               // ��������
  int            iDataDate;              // ��������
  int            iDataTime;              // ����ʱ��
  int            iIndex;                 // �ɽ����(��1��ʼ������1)
  char           chFunctionCode;         // �ɽ�����: 'C', 0
  char           chOrderKind;            // �ɽ�����
  char           chBSSide;               // ��������:0:�� 1:�� ����:
  unsigned int   uiPrice;                // �ɽ���
  unsigned int   uiMatchedVol;           // �ɽ���
  int            iAskOrderNo;            // �������
  int            iBidOrderNo;            // �������
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//ǧ������
#define THOUNSAND_DATA_NUM    500
#define TSD_SINGLE_QUEUE_SIZE 200

//ǧ����һ��������
struct MACLIAPI ST_MKT_DATA_TSD_SINGLE
{
  unsigned int uiPrice;     // ��
  int          iVol;        // ��
  int          iQueueSize;  // ���г���
  int          iQueues[TSD_SINGLE_QUEUE_SIZE];  // ί�ж���
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char *p_szFmtMktDataStr, int p_iPos);
};

//ǧ������
struct MACLIAPI ST_MKT_THOUNSAND_DATA
{
  bool         bInitialized;
  char         chExchange;             // ������
  char         szTrdCode[16 + 1];      // Ʒ�ִ���
  long long    llMktDataTime;          // ����ʱ��
  int          iDataDate;              // ��������
  int          iDataTime;              // ����ʱ��
  int          iBidNum;                // ��ĵ���
  ST_MKT_DATA_TSD_SINGLE stBid[THOUNSAND_DATA_NUM]; // ����
  int          iOffNum;                // ���ĵ���
  ST_MKT_DATA_TSD_SINGLE stOff[THOUNSAND_DATA_NUM]; // ����
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char *p_szFmtMktDataStr);
};

struct ST_EXCHANGE_CVT
{
  char chExchange;
  char szHongHuiType[3+1];
  char szTsType[2+1];
};

#pragma pack()

const ST_EXCHANGE_CVT g_stExchangeCvt[] =
{
  {'0', "SZ",  "SZ"},   // ����֤ȯ������
  {'1', "SH",  "SH"},   // �Ϻ�֤ȯ������
  {'A', "SHF", "SQ"},   // �Ϻ��ڻ�������
  {'B', "DCE", "DL"},   // �����ڻ�������
  {'C', "CZC", "ZZ"},   // ֣���ڻ�������
  {'G', "CF",  "ZJ"},   // �й������ڻ�������
  {'7', "HK",  "HK"},   // ��۽�����
  {'2', "BJ",  "BJ"},   // ��ת֤ȯ������
  {'I', "NY",  "NY"},   // ��Դ���齻����
  {'3', "BJ",  "BJ"},   // ����֤ȯ������
};

#endif  // __MA_MKT_DATA_H__
