#include <iostream>
#include <string>
#include <sstream>

bool check (std::string example){
    bool res= true;
    int count=0;
    int i=0;
    for (i; i<example.size(); i++) {

            if (i==0 && (example[i]<'0' || example[i]>'9')) {
                res= false;
                break;
            }
            else if ((example[i]<'0'|| example[i]>'9') && (example[i]!='/'&& example[i]!='+'&& example[i]!='-'&& example[i]!='*')) {
                res= false;
                break;
            }
            else if ((example[i]=='/'||example[i]=='+'||example[i]=='-'||example[i]=='*')
                     && (example[i+1]<'0'||example[i+1]>'9')) {
                res= false;
                break;
            }
            if(example[i]=='/'||example[i]=='+'||example[i]=='-'||example[i]=='*'){
                count++;
            }
    }
    if (count==0||count>1) {
        res = false;

    }

    return res;

};

int main() {

    double number_1, number_2;
    char math_action='0';

    std::string example;
    std::cout << "Enter example - " << std::endl;
    std::cin >> example;
    std::string temp_number_1="0";
    std::string temp_number_2="0";

    if (!check(example)) {
        std::cout << "The example is incorrect!" << std::endl;

    }
    else {
        for(int i=0; i<example.size(); i++){
            if ((example[i]!='/' && example[i]!='+' && example[i]!='-' && example[i]!='*') && math_action=='0'){
                temp_number_1+=example[i];
            }
            else if ((example[i]!='/'&&example[i]!='+'&&example[i]!='-'&&example[i]!='*') && math_action!='0'){

                temp_number_2+=example[i];

            }
            else if (example[i]=='/'|| example[i]=='+' || example[i]=='-' || example[i]=='*'){
                math_action = example[i];
            }
            //std::cout << temp_number_1 <<" "<< temp_number_2 << " " << math_action<< std::endl;
        }
    }
    number_1=std::stod(temp_number_1);
    number_2=std::stod(temp_number_2);
    if (math_action=='/'){
        if (number_2==0){
            std::cout << "It cannot be divided by 0!";
        }
        else{
            std::cout << number_1/number_2;
        }
    }
    else if(math_action=='*'){
        std::cout << "= "<<number_1*number_2;
    }
    else if(math_action=='+'){
        std::cout << "= "<<number_1+number_2;
    }
    else if(math_action=='-'){
        std::cout << "= "<< number_1-number_2;
    }
    //std::cout << number_1<< " "<< number_2 << " " << temp_number_1 << " "<< temp_number_2;

    return 0;
}
