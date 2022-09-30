#include <stdio.h>
#include <string.h>

int MyPow(int a,int b){
if(b<0)      
    return 1 / MyPow (a,-b);
else if(b==0)
    return 1;
else if(b==1)
    return a;
else
    return a*MyPow(a,b-1);
}

int highestbase(int number, int base){
    int highbase = 0;
    while (number>MyPow(base,highbase)){
        highbase++;
    }
    highbase--;
    return highbase;
}

char hexadecimalconverter(char number){
    switch(number){
            case ':': number = 'A'; break;
            case ';': number = 'B'; break;
            case '<': number = 'C'; break;
            case '=': number = 'D'; break;
            case '>': number = 'E'; break;
            case '?': number = 'F'; break;
            default: number = number; break;
        }
    return number;
}

char antihexconverter(char number){
    switch(number){
            case 'A': number = ':'; break;
            case 'B': number = ';'; break;
            case 'C': number = '<'; break;
            case 'D': number = '='; break;
            case 'E': number = '>'; break;
            case 'F': number = '?'; break;
            default: number = number; break;
        }
    return number;
}


int converter(int number, int base){
    char convert[100];
    int product, remainder;
    int i = 0;
    product = number;
    char a;
    while (product != 0){
        remainder = product%base;
        product = product/base;
        //printf("product is %d\n", product);
        //printf("remainder is %d\n", remainder);
        convert[i] = hexadecimalconverter(remainder + '0');
        i++;
    }
    convert[i] = remainder;
    printf("Output=");
    //printf("%d", highestbase(number, base));
    for (int k = highestbase(number, base); k > -1 ; k--){
        printf("%c", convert[k]);
    } 
    printf("\n\n");
    return 0;
}


int main(){
    char *int1;
    int int2 = 0, int3 = 0;
    
    printf("Please enter a set of number:\n");
    scanf("%s", int1);

    printf("Please enter the current number system:\n");
    scanf("%d", &int2);
    if (int2 != 2 && int2 != 16 && int2 != 10){
        printf("Error! The number system is not supported.");
        return 0;
    }

    for (char *k = int1; *k != '\0'; k++){
        *k = antihexconverter(*k);
    }
    

    //here make the error: "Error! That set of number is not a binary number."
    //check every input from *int1
    if (int2 == 2){
        for (char *k = int1; *k != '\0'; k++) {
            if (*k != '0' && *k != '1'){
                printf("Error! That set of number is not a binary number.");
                return 0;
            }
        }
    }
    else if (int2 == 10){
        for (char *k = int1; *k != '\0'; k++) {
            if (*k != '0' && *k != '1' && *k != '2' && *k != '3' && *k != '4'
            && *k != '5' && *k != '6' && *k != '7' && *k != '8' && *k != '9' ){
                printf("Error! That set of number is not a decimal number.");
                return 0;
            }
        }
    }
    else{
        for (char *k = int1; *k != '\0'; k++) {
            //printf("%d", *k);
            if (*k != '0' && *k != '1' && *k != '2' && *k != '3' && *k != '4'
            && *k != '5' && *k != '6' && *k != '7' && *k != '8' && *k != '9' 
            && *k != ':' && *k != ';' && *k != '<' && *k != '=' && *k != '>'
            && *k != '?'){
                printf("Error! That set of number is not a hexadecimal number.");
                return 0;
            }
        }
    }
    //

    //STEP 1: CONVERT char input INTO decimal integer(variable num)
    
    char *l;
    int num = 0;
    for (l = int1; *l != '\0'; l++) {
        num *= int2;
        num += *l-48;
    }
    //printf("%d",num);//prints out wanted number in num

    printf("Please enter the number system you want the set of number be converted to:\n");
    scanf("%d", &int3);
    if (int3 != 2 && int3 != 16 && int3 != 10){
        printf("Error! The number system is not supported.");
        return 0;
    }

    converter(num, int3);
    return 0;
}