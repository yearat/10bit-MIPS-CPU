#include <bits/stdc++.h>

using namespace std;


void createMap(unordered_map<string, char> *um)
{
    (*um)["0000"] = '0';
    (*um)["0001"] = '1';
    (*um)["0010"] = '2';
    (*um)["0011"] = '3';
    (*um)["0100"] = '4';
    (*um)["0101"] = '5';
    (*um)["0110"] = '6';
    (*um)["0111"] = '7';
    (*um)["1000"] = '8';
    (*um)["1001"] = '9';
    (*um)["1010"] = 'A';
    (*um)["1011"] = 'B';
    (*um)["1100"] = 'C';
    (*um)["1101"] = 'D';
    (*um)["1110"] = 'E';
    (*um)["1111"] = 'F';
}


string convertBinToHex(string bin)
{
    int l = bin.size();
    int t = bin.find_first_of('.');


    int len_left = t != -1 ? t : l;


    for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
        bin = '0' + bin;


    if (t != -1)
    {

        int len_right = l - len_left - 1;

        for (int i = 1; i <= (4 - len_right % 4) % 4; i++)
            bin = bin + '0';
    }

    unordered_map<string, char> bin_hex_map;
    createMap(&bin_hex_map);

    int i = 0;
    string hex = "";

    while (1)
    {

        hex += bin_hex_map[bin.substr(i, 4)];
        i += 4;
        if (i == bin.size())
            break;

        if (bin.at(i) == '.')
        {
            hex += '.';
            i++;
        }
    }


    return hex;
}


int main()
{



    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map <string,string> mp;
    map <string,string> library;

    library["AND"]  = "0000"; //0000 ADDITION
    library["OR"]   = "0001"; //0001 SUBTRACTION
    library["ADD"]  = "0010";//0010 AND
    library["SUB"]  = "0011"; //0011 OR
    library["ANDI"] = "1000"; //0100 XOR
    library["ORI"]  = "1001"; //0100 LOAD
    library["ADDI"] = "1010"; // 0101 STORE
    library["SUBI"] = "1011";
    library["SW"]   = "1101";
    library["LW"]   = "1110";
    library["BEQ"]  = "1111";

    string regivals[] = {"00","01","10","11"}; //REGISTER NUMBERS


    int program_counter = 0;
    int adress = 0;
    int imdt;
    string opcode,oprnd1,oprnd2,oprnd3;
    map<string,string>::iterator itr;


    int regi_num = 0;
    map <string,string> registers;
    ifstream myReadFile;
    myReadFile.open("registers.txt"); // GRTIING REGISTER NAMES
    char output[100];
    if (myReadFile.is_open()) {
    while (!myReadFile.eof()) {


        myReadFile >> output;
        registers[output] = regivals[regi_num++]; //ASSIGNING REGISTER ADDRESS


        }
    }
    myReadFile.close();

    //cout << registers["R1"] << " " << registers["R2"] << " " << registers["R3"] << " " << registers["R4"] << " " << endl;



    while(cin >> opcode) {
        program_counter++;
        if(opcode == "END")
        {
            return 0;
        }
        if(opcode == "ADD") {


                        cin >> oprnd1 >> oprnd2 >> oprnd3;
                        cout << library[opcode] << " " << registers[oprnd2] << " " << registers[oprnd3] << " " << registers[oprnd1] << endl;
                        string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd2];
                        bin += registers[oprnd3];
                        bin += registers[oprnd1];
                        cout << "HEX : " << convertBinToHex(bin) << endl;
               }

        if(opcode == "SUB") {
                    cin >> oprnd1 >> oprnd2 >> oprnd3;
                     cout << library[opcode] << " " << registers[oprnd2] << " " << registers[oprnd3] << " " << registers[oprnd1] << endl;
                      string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd2];
                        bin += registers[oprnd3];
                        bin += registers[oprnd1];
                        cout << "HEX : " << convertBinToHex(bin) << endl;

               }

        if(opcode == "AND") {
                    cin >> oprnd1 >> oprnd2 >> oprnd3;
                    cout << library[opcode] << " " << registers[oprnd2] << " " << registers[oprnd3] << " " << registers[oprnd1] << endl;
                     string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd2];
                        bin += registers[oprnd3];
                        bin += registers[oprnd1];
                        cout << "HEX : " << convertBinToHex(bin) << endl;
               }

        if(opcode == "OR") {
                    cin >> oprnd1 >> oprnd2 >> oprnd3;
                     cout << library[opcode] << " " << registers[oprnd2] << " " << registers[oprnd3] << " " << registers[oprnd1] << endl;
                      string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd2];
                        bin += registers[oprnd3];
                        bin += registers[oprnd1];
                        cout << "HEX : " << convertBinToHex(bin) << endl;

               }

            if(opcode== "LW") {
                cin >> oprnd1 >> imdt >> oprnd2;
                cout << library[opcode] << " " << registers[oprnd2] << " " << registers[oprnd1] << " " << regivals[imdt] << endl;
                 string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd2];
                        bin += registers[oprnd1];
                        bin += regivals[imdt];
                        cout << "HEX : " << convertBinToHex(bin) << endl;
            }


            if(opcode== "SW") {
                cin >> oprnd1 >> imdt >> oprnd2;
                 cout << library[opcode] << " " << registers[oprnd1] << " " << registers[oprnd2] << " " << regivals[imdt] << endl;
                  string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd1];
                        bin += registers[oprnd2];
                        bin += regivals[imdt];
                        cout << "HEX : " << convertBinToHex(bin) << endl;
            }


            if(opcode== "ANDI") {
                cin >> oprnd1 >> oprnd2 >> imdt;
                 cout << library[opcode] << " " << registers[oprnd2] << " " << registers[oprnd1] << " " << regivals[imdt] << endl;
                  string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd2];
                        bin += registers[oprnd1];
                        bin += regivals[imdt];
                        cout << "HEX : " << convertBinToHex(bin) << endl;
            }

            if(opcode== "ADDI") {
                cin >> oprnd1 >> oprnd2 >> imdt;
                 cout << library[opcode] << " " << registers[oprnd2] << " " << registers[oprnd1] << " " << regivals[imdt] << endl;
                  string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd2];
                        bin += registers[oprnd1];
                        bin += regivals[imdt];
                        cout << "HEX : " << convertBinToHex(bin) << endl;
            }
            if(opcode== "ORI") {
                cin >> oprnd1 >> oprnd2 >> imdt;
                 cout << library[opcode] << " " << registers[oprnd2] << " " << registers[oprnd1] << " " << regivals[imdt] << endl;
                  string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd2];
                        bin += registers[oprnd1];
                        bin += regivals[imdt];
                        cout << "HEX : " << convertBinToHex(bin) << endl;
            }
            if(opcode== "SUBI") {
                cin >> oprnd1 >> oprnd2 >> imdt;
                 cout << library[opcode] << " " << registers[oprnd2] << " " << registers[oprnd1] << " " << regivals[imdt] << endl;
                  string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd2];
                        bin += registers[oprnd1];
                        bin += regivals[imdt];
                        cout << "HEX : " << convertBinToHex(bin) << endl;
            }
            if(opcode == "BEQ") {
                cin >> oprnd1 >> oprnd2 >> imdt;
                 cout << library[opcode] << " " << registers[oprnd1] << " " << registers[oprnd2] << " " << regivals[imdt] << endl;
                  string bin = "";
                        bin += library[opcode];
                        bin += registers[oprnd1];
                        bin += registers[oprnd2];
                        bin += regivals[imdt];

                        cout << "HEX : " << convertBinToHex(bin) << endl;
            }


    }


    return 0;
}
