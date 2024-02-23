#ifndef MACDECODER_H
#define MACDECODER_H
#include<iostream>
#include<unordered_map>
#include "mac_decoder.h"
using namespace std;

/*Function to find value of subheader Downlink*/
void find_subheader_val_DL(uint8_t data, MAC_HEADER& sub_head){
    fstream file2;
    file2.open("output_DL.txt", ios::in | ios::out | ios::app);
    if (file2.is_open()) {
    sub_head.R1=(data >> 7) & 1;
    cout<<" Value of R1: "<<static_cast<int>(sub_head.R1)<<endl;
    file2<<"Value of R1="<<static_cast<int>(sub_head.R1)<<endl;
    sub_head.R2=(data >> 6) & 1;
    cout<<" Value of R2: "<<static_cast<int>(sub_head.R2)<<endl;
    file2<<"Value of R2="<<static_cast<int>(sub_head.R2)<<endl;
    sub_head.E =(data >> 5) & 1;
    cout<<" Value of E: "<<static_cast<int>(sub_head.E)<<endl;
    file2<<"Value of E="<<static_cast<int>(sub_head.E)<<endl;
    file2.close();
    }
    else{
        cout << " Unable to open the file. " <<endl;
    }
    sub_head.LCID = data & 0x1F;
    int lcid_data = static_cast<int> (sub_head.LCID);
    print_downlink_LCID_val(lcid_data);
}

/* Function to find value of subheader Uplink */
void find_subheader_val_UL(uint8_t data, MAC_HEADER& sub_head){
    fstream file3;
    file3.open("output_UL.txt", ios::in | ios::out | ios::app);
    if (file3.is_open()) {
    sub_head.R1=(data >> 7) & 1;
    cout<<" Value of R1: "<<static_cast<int>(sub_head.R1)<<endl;
    file3<<"Value of R1="<<static_cast<int>(sub_head.R1)<<endl;
    sub_head.R2=(data >> 6) & 1;
    cout<<" Value of R2: "<<static_cast<int>(sub_head.R2)<<endl;
    file3<<"Value of R2="<<static_cast<int>(sub_head.R2)<<endl;
    sub_head.E =(data >> 5) & 1;
    cout<<" Value of E: "<<static_cast<int>(sub_head.E)<<endl;
    file3<<"Value of E="<<static_cast<int>(sub_head.E)<<endl;
    file3.close();
    }
    else{
        cout << " Unable to open the file. " <<endl;
    }
    sub_head.LCID = data & 0x1F;
    int lcid_data = static_cast<int> (sub_head.LCID);
    print_uplink_LCID_val(lcid_data);
}

#endif