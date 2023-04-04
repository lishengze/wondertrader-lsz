#if !defined(__MA_CLI_STK_MKT_DATA_H__)
#define __MA_CLI_STK_MKT_DATA_H__

#include "maMktData.h"
#include "maCliTradeApi.h"
#include "maCliMktDataStruct.h"
#include "maCliStkTradeApiStruct.h"
#include "maCliOptTradeApiStruct.h"
#include "maCliFislTradeApiStruct.h"
#include "maCliFutureTradeApiStruct.h"
#include "maCliCosTradeApiStruct.h"

BGN_NAMESPACE_MACLI

class MACLIAPI CCliMktDataSpi
{
public:
  // �ͻ�����������ɹ�����ͨ�����Ӻ󣬸÷���������
  virtual int OnConnected(void) {return 0;}

  // �ͻ�����������ɹ���ͨ�����ӶϿ�ʱ���÷���������
  virtual int OnDisconnected(int p_nReason, const char *p_pszErrInfo) {return 0;}
  
  // ��¼��̨����ϵͳ
  virtual int OnRspCosLogin(CFirstSetField *p_pFirstSet, CRspCosLoginField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ֻ�/�����û���¼������Ӧ
  virtual int OnRspStkUserLogin(CFirstSetField *p_pFirstSetField, CRspStkUserLoginField *p_pRsqField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  
  // ��Ȩ�û���¼������Ӧ
  virtual int OnRspOptUserLogin(CFirstSetField *p_pFirstSetField, CRspOptUserLoginField *p_pRsqField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ڻ��û���¼������Ӧ
  virtual int OnRspFutureUserLogin(CFirstSetField *p_pFirstSetField, CRspFutureUserLoginField *p_pRsqField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �������������Ӧ
  virtual int OnRspHeartBeat(CFirstSetField *p_pFirstSetField, CRspHeartBeatField *p_pRsqField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  
  // ����ط�������Ӧ
  virtual int OnRspPlayBack(CFirstSetField *p_pFirstSetField, CRspPlayBackField *p_pRsqField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ������Ӧ
  virtual int OnRtnSubMktData(CRspSubTopicField* p_pRspSubField) {return 0;}

  // ȡ��������Ӧ
  virtual int OnRtnUnsubMktData(CRspUnsubTopicField* p_pRspUnsubField) {return 0;}

  // ��ѡ�ɱ༭
  virtual int OnRspPortfolio(CFirstSetField *p_pFirstSet, CRspMktDataPortfolioField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ��ѡ�ɲ�ѯ
  virtual int OnRspQryPortfolioInfo(CFirstSetField *p_pFirstSet, CRspMktDataPortfolioInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // k������
  virtual int OnRspQryKData(CFirstSetField *p_pFirstSet, CRspMktDataKDataField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // tick����
  virtual int OnRspQryTickSnapshot(CFirstSetField *p_pFirstSet, CRspMktDataTickSnapshotField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ǧ������
  virtual int OnRspQryThounsandData(CFirstSetField *p_pFirstSet, CRspMktDataThounsandDataField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  
  // ָ����ֵ��ѯ��Ӧ
  virtual int OnRspQryIndexVal(CFirstSetField *p_pFirstSetField, CRspMktDataQryIndexValField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  
  // ��ָ�����������Ӧ
  virtual int OnRspQryCloudIndex(CFirstSetField *p_pFirstSetField, CRspMktDataQryCloudIndexField *p_pRspField, LONGLONG p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����������Ӧ(��Ȩ���ֻ����ڻ�)
  virtual int OnRtnMktData(ST_MKT_DATA* p_pMktData) {return 0;}

  // ����������Ӧ(��Ȩ���ֻ����ڻ�)
  virtual int OnRtnMktData(ST_MKT_DATA2* p_pMktData) {return 0;}

  // ����������Ӧ(��Ȩ���ֻ����ڻ�)
  virtual int OnRtnMktData(ST_MKT_DATA3* p_pMktData) {return 0;}

  // ��ʱ�ɽ���Ӧ
  virtual int OnRtnMktMatch(ST_MKT_MATCH* p_pMktData) {return 0;}
  
  // ���ί����Ӧ
  virtual int OnRtnMktOrder(ST_MKT_ORDER* p_pMktData) {return 0;}
  
  // ָ��������Ӧ
  virtual int OnRtnMktIndex(ST_MKT_INDEX* p_pMktData) {return 0;}

  // ��ʳɽ���Ӧ
  virtual int OnRtnMktTransaction(ST_MKT_TRANSACTION* p_pMktData) {return 0;}

  // ί�ж�����Ӧ
  virtual int OnRtnMktOrderQueue(ST_MKT_ORDER_QUEUE* p_pMktData) {return 0;}

  // ǧ��������Ӧ
  virtual int OnRtnMktThounsandData(ST_MKT_THOUNSAND_DATA* p_pMktData) {return 0;}
};

class MACLIAPI CCliMktDataApi
{
public:
  // Ĭ�Ϲ��캯��
  CCliMktDataApi(void);

  // ��������
  virtual ~CCliMktDataApi(void);

  // ��ʼ��
  virtual int Init(void);

  // �˳�
  virtual int Exit(void);

  // ע��������Ϣ
  virtual int RegisterServer(const char *p_pszIp, int p_iPort, bool p_bCos = false, int p_iSsl = -1);

  // ע��������Ϣ
  virtual int RegisterServer(CReqSysField* p_pstSysField);

  // ע��ص��ӿ�
  virtual int RegisterSpi(CCliMktDataSpi *p_pSpi);

  // ע���˺���Ϣ
  virtual int RegisterAcct(char p_chChannel, const char *p_pszSession);

  // ע���˺���Ϣ
  virtual int RegisterAcct(CReqFixField* p_pstFixField);

  // ����ϵͳע�Ṧ������
  virtual int ReqCosLogin(CReqCosLoginField *p_pReqField, LONGLONG p_llRequestId);

  // �û��ֻ���¼����
  virtual int ReqStkUserLogin(CReqStkUserLoginField *p_pReqField, LONGLONG p_llRequestId);

  // �û���Ȩ��¼����
  virtual int ReqOptUserLogin(CReqOptUserLoginField *p_pReqField, LONGLONG p_llRequestId);

  // �û��ڻ���¼����
  virtual int ReqFutureUserLogin(CReqFutureUserLoginField *p_pReqField, LONGLONG p_llRequestId);

  // �û����õ�¼����
  virtual int ReqFislUserLogin(CReqFislUserLoginField *p_pReqField, LONGLONG p_llRequestId);

  // �����������
  virtual int ReqHeartBeat(CReqHeartBeatField *p_pReqField, LONGLONG p_llRequestId);

  // ����ط�����
  virtual int ReqPlayBack(CReqPlayBackField * p_pPlayBack,LONGLONG p_llRequestID);

  // ��ѡ�ɱ༭
  virtual int ReqPortfolio(CReqMktDataPortfolioField *p_pReqField, LONGLONG p_llRequestId);

  // ��ѡ�ɲ�ѯ
  virtual int ReqQryPortfolioInfo(CReqMktDataPortfolioInfoField *p_pReqField, LONGLONG p_llRequestId);

  // k������
  virtual int ReqQryKData(CReqMktDataKDataField *p_pReqField, LONGLONG p_llRequestId);

  // tick����
  virtual int ReqQryTickSnapshot(CReqMktDataTickSnapshotField *p_pReqField, LONGLONG p_llRequestId);

  // ǧ�������ѯ
  virtual int ReqQryThounsandData(CReqMktDataThounsandDataField *p_pReqField, LONGLONG p_llRequestId);
  
  // ָ����ֵ��ѯ����
  virtual int ReqQryIndexVal(CReqMktDataQryIndexValField *p_pReqField, LONGLONG p_llRequestId);
  
  // ��ָ�������������
  virtual int ReqQryCloudIndex(CReqMktDataQryCloudIndexField *p_pReqField, LONGLONG p_llRequestId);

  // ��ȡ��������Ϣ
  virtual const char* GetLastErrorText(void);

public:
  // �첽�ص�����
  void OnArCallback(const char *p_pszMsgId, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // �����ص�����
  void OnPsCallback(const char *p_pszAcceptSn, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // ��������
  int SubMktData(CReqSubTopicField* p_pReqSubField);

  // �˶�����
  int UnsubMktData(CReqUnsubTopicField* p_pReqUnsubField);

private:
  // ����ҵ���ͷ��Ϣ
  int SetBizPackHead(const char *p_pszFuncId, LONGLONG p_llRequestId, char *p_pszMsgId, char p_chPkgType);

  // ����������Ӧ
  void OnRspSubMktData(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �˶�������Ӧ
  void OnRspUnsubMktData(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  
  // ����ϵͳע�Ṧ����Ӧ
  void OnRspCosLogin(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);

  // �û��ֻ�/���õ�¼������Ӧ
  void OnRspStkUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // �û���Ȩ��¼������Ӧ
  void OnRspOptUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // �û��ڻ���¼������Ӧ
  void OnRspFutureUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // �������������Ӧ
  void OnRspHeartBeat(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // ����ط�������Ӧ
  void OnRspPlayBack(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // ��ѡ�ɱ༭
  void OnRspPortfolio(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);

  // ��ѡ�ɲ�ѯ
  void OnRspQryPortfolioInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);

  // k������
  void OnRspQryKData(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);

  // tick����
  void OnRspQryTickSnapshot(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);

  // ǧ������
  void OnRspQryThounsandData(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
  
  // ָ����ֵ��ѯ��Ӧ
  void OnRspQryIndexVal(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  
  // ��ָ�����������Ӧ
  void OnRspQryCloudIndex(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

private:
  void*              m_hAsynCall;        // ϵͳ���þ��
  void*              m_hAnsParse;        // Ӧ�������
  void*              m_hPubParse;        // ���ͽ�����
  CReqSysField       m_stSysField;       // ϵͳ���Ӳ���
  CReqFixField       m_stReqFixField;    // ����̶�����
  CCliMktDataSpi    *m_pMktDataSpi;      // �ص�ʵ��ָ��
  bool               m_bIsLogin;
  bool               m_bIsCos;
  char               m_szLastErrorText[1024+1]; // ��������Ϣ
};

END_NAMESPACE_MACLI

#endif  //__MA_CLI_STK_MKT_DATA_H__