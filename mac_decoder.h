#include<iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include<fstream>
using namespace std;

/* structure to store sub header value */
struct MAC_HEADER{
    uint8_t header;
    uint8_t R1,R2,E,LCID;
};

/* function declaration */
void find_subheader_val_UL(uint8_t hex_dec,MAC_HEADER& var1);
void find_subheader_val_DL(uint8_t hex_dec,MAC_HEADER& var1);
void downlink();
void uplink();
void print_downlink_LCID_val(int lcid_data);
void print_uplink_LCID_val(int lcid_data);
