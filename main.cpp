#ifndef MACDECODER_H
#define MACDECODER_H
#define DEBUG_ENABLE
#include<iostream>
#include "mac_decoder.h"
using namespace  std;

int main(){
    int choice;
    string hexadecimal;
    while(1){
        cout<<" ****************************************"<<endl;
        cout<<"Enter the valid option for finding LCID "<<endl;
        cout<<"1.Finding the LCID value MAC-PDU decoder DOWNLINK"<<endl;
        cout<<"2.Finding the LCID value MAC-PDU decoder UPLINK"<<endl;
        cout<<"3.EXIT FROM EXECUTION "<<endl;
        cout<<" ****************************************"<<endl;
        cin>>choice;
        switch(choice){
            
            case 1: remove("output_DL.txt");//remove file to avoid appending multiple times with same content.
                    downlink();//Find the value of LCID for downlink
                    break;

            case 2: remove("output_UL.txt");
                    uplink();//Find the value of LCID for uplink
                    break;
            case 3:exit(0);//exit 
                    break;
            default:
                    cout<<"Enter valid option"<<endl;
                    break;
        }
    }
    return 0;
}

#endif