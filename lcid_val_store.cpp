#ifndef MACDECODER_H
#define MACDECODER_H
#include<iostream>
#include<unordered_map>
#include "mac_decoder.h"

/* Function to print and store the value of LCID in file for Downlink*/
void print_downlink_LCID_val(int lcid_val){
    cout<<"LCID Val for downlink "<<endl;
    fstream file;
    file.open("output_DL.txt", std::ios::in | std::ios::out | std::ios::app);
    if (file.is_open()) {
        file << "LCID Val for  downlink" << std::endl;
        // Lookup table for switch cases
        std::unordered_map<int, std::string> lcidLookupTable = {
            {0, "CCCH"},
            {1, "Identity of the logical channel"},
            {2, "Identity of the logical channel"},
            {3, "Identity of the logical channel"},
            {4, "Identity of the logical channel"},
            {5, "Identity of the logical channel"},
            {6, "Identity of the logical channel"},
            {7, "Identity of the logical channel"},
            {8, "Identity of the logical channel"},
            {9, "Identity of the logical channel"},
            {10, "Identity of the logical channel"},
            {11, "Reserved"},
            {12, "Reserved"},
            {13, "Reserved"},
            {14, "Reserved"},
            {15, "Reserved"},
            {16, "Reserved"},
            {17, "Reserved"},
            {18, "Reserved"},
            {19, "Reserved"},
            {20, "Reserved"},
            {21, "Reserved"},
            {22, "Reserved"},
            {23, "Reserved"},
            {24, "Reserved"},
            {25, "Reserved"},
            {26, "Long DRX Command"},
            {27, "Activation/Deactivation"},
            {28, "UE Contention Resolution Identity"},
            {29, "Timing Advance Command"},
            {30, "DRX Command"},
            {31, "Padding"}
        }; 

        auto iter = lcidLookupTable.find(lcid_val);
        if (iter != lcidLookupTable.end()) {
            std::cout << iter->second << std::endl;
            file << iter->second << std::endl;
        } else {
            std::cout << "Invalid LCID" << std::endl;
        }
         file.close();
    }
     else {
        cout << " Unable to open the file. " <<endl;
    }
}

/* Function to print and store the value of LCID in file for Uplink*/
void print_uplink_LCID_val(int lcid_val){
    cout<<"LCID Val for uplink "<<endl;
    std::fstream file1;
    file1.open("output_UL.txt", std::ios::in | std::ios::out | std::ios::app);
    if (file1.is_open()) {
        file1 << "LCID Val for uplink" << std::endl;

        // Lookup table for switch cases
        std::unordered_map<int, std::string> lcidLookupTable = {
            {0, "CCCH"},
            {1, "Identity of the logical channel"},
            {2, "Identity of the logical channel"},
            {3, "Identity of the logical channel"},
            {4, "Identity of the logical channel"},
            {5, "Identity of the logical channel"},
            {6, "Identity of the logical channel"},
            {7, "Identity of the logical channel"},
            {8, "Identity of the logical channel"},
            {9, "Identity of the logical channel"},
            {10, "Identity of the logical channel"},
            {11, "CCCH"},
            {12, "Reserved"},
            {13, "Reserved"},
            {14, "Reserved"},
            {15, "Reserved"},
            {16, "Reserved"},
            {17, "Reserved"},
            {18, "Reserved"},
            {19, "Reserved"},
            {20, "Reserved"},
            {21, "Reserved"},
            {22, "Truncated Sidelink BSR"},
            {23, "Sidelink BSR"},
            {24, "Dual Connectivity Power Headroom Report"},
            {25, "Extended Power Headroom Report"},
            {26, "Power Headroom Report"},
            {27, "C-RNTI"},
            {28, "Truncated BSR"},
            {29, "Short BSR"},
            {30, "Long BSR"},
            {31, "Padding"}
        };
        auto iter = lcidLookupTable.find(lcid_val);
        if (iter != lcidLookupTable.end()) {
            std::cout << iter->second << std::endl;
            file1 << iter->second << std::endl;
        } else {
            std::cout << "Invalid LCID" << std::endl;
        }
        file1.close();
    }
    else {
        cout << " Unable to open the file. " <<endl;
    }
}

#endif