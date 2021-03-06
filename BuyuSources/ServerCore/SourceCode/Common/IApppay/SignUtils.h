/* 
 * File:   SignUtils.h
 * Author: Administrator
 *
 * Created on 2015年8月31日, 下午3:28
 */

#ifndef SIGNUTILS_H
#define	SIGNUTILS_H

#include "CryptHelper.h"
#include <cstdlib>
//#include <curl/curl.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <windows.h>
//#include "IAppPaySDKConfig.h"

class SignUtils {
public:
    SignUtils();
    SignUtils(const SignUtils& orig);
    virtual ~SignUtils();
    //static int32_t reqData(const std::string content,std::string &reqData);
    static std::vector<std::string> splitString(const std::string& srcStr,const char ch);
   // static int32_t curlPost(const std::string& httpUrl, const std::string& postBody, const std::string& encoding,std::string &reqData);
    static void getData(const std::string &respData, std::string &transdata,std::string &sign,std::string &signtype);
    //static void verifySignData(const std::string transdata, const std::string sign, const std::string signtype);
    
    static void UTF_8ToGB2312(const char *pText, int pLen, std::string &pOut);//utf_8转为gb2312
    static void GB2312ToUTF_8(const char *pText, int pLen, std::string& pOut); //gb2312 转utf_8
    static std::string UrlGB2312(const char * str);                           //urlgb2312编码
    static std::string UrlUTF8(const char * str);                             //urlutf8 编码
    static std::string UrlUTF8Decode(const std::string str);                  //urlutf8解码
    static std::string UrlGB2312Decode(const std::string str);                //urlgb2312解码
private:
    static void Gb2312ToUnicode(WCHAR* pOut,const char *gbBuffer);
    static void UTF_8ToUnicode(WCHAR* pOut,const char *pText);
    static void UnicodeToUTF_8(char* pOut,const WCHAR* pText);
    static void UnicodeToGB2312(char* pOut,const WCHAR uData);
    static char CharToInt(const char ch);
    static char StrToBin(const char *str);
};

#endif	/* SIGNUTILS_H */

