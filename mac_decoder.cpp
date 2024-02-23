#ifndef MACDECODER_H
#define MACDECODER_H
#include<iostream>
#include "mac_decoder.h"
using namespace std;
MAC_HEADER obj2;

/* function to start with find value of LCID for downlink*/
void downlink(){
    /* FOR EACH HEXA VALUE FROM RANGE 0 TO 255 i.e 0X00 TO 0XFF*/
    for (int i = 0x00; i <= 0xFF; ++i) {
        std::ostringstream oss;
        oss << std::hex << std::setw(2) << std::setfill('0') << i;
        std::string hexadecimal = oss.str().substr(oss.str().size() - 2);
        cout<<"Hexadecimalvalue="<<hexadecimal<<endl;

        obj2.header = static_cast<int8_t>(std::stoi(hexadecimal, nullptr, 16));
        cout << "Converted MAC_PDU  header: " << static_cast<int>(obj2.header) <<endl;
        /*writing onto the files*/
        ofstream file1("output_DL.txt", std::ios::out | std::ios::app); // Open file1.txt in write mode

        if (file1.is_open()) {
            // Write content to file1.txt
            file1 << "Converted MAC_PDU  header: " << static_cast<int>(obj2.header) <<endl;
            file1.close(); // Close file1.txt
        } else {
            std::cout << "Unable to open the files." << std::endl;
        }
    uint8_t dec_hex = stoi(hexadecimal, 0, 16);
    find_subheader_val_DL(dec_hex,obj2);
    }
}

/* function to start with find value of LCID for uplink*/
void uplink(){
    /* FOR EACH HEXA VALUE FROM RANGE 0 TO 255 i.e 0X00 TO 0XFF*/
    for (int i = 0x00; i <= 0xFF; ++i) {
        std::ostringstream oss;
        oss << std::hex << std::setw(2) << std::setfill('0') << i;
        std::string hexadecimal = oss.str().substr(oss.str().size() - 2);
        cout<<"Hexadecimalvalue"<<hexadecimal<<endl;

        obj2.header = static_cast<int8_t>(std::stoi(hexadecimal, nullptr, 16));
        cout << "Converted MAC_PDU  header: " << static_cast<int>(obj2.header) <<endl;
        /*writing onto the file*/
        ofstream file2("output_UL.txt", std::ios::out |std::ios::app); // Open file2.txt in append mode

        if (file2.is_open()) {
            //  write | Append content to file2.txt
            file2 << "Converted MAC_PDU  header: " << static_cast<int>(obj2.header) <<endl;
            file2.close(); // Close file2.txt
        } else {
            std::cout << "Unable to open the files." << std::endl;
        }
    uint8_t dec_hex = stoi(hexadecimal, 0, 16);
    find_subheader_val_UL(dec_hex,obj2);
    }
}

#endif