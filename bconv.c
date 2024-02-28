//Bayleigh Andersen
//February 27, 2024
//CSCI 304
/*This program prints out a menu and options, along with a value displayed in different bases. The default value
is 0 and the menu should be displayed until a valid option is inputed.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
char print_menu();


short get_operand (char mode) // read in numeric value in mode; return value
{
    short input_val;
    switch(mode)
    {
        case 'O': 
            printf("Enter value in Octal mode\n");
            scanf("%ho",&input_val);
            printf("Value = %o\n", input_val);
            break;
        case 'H':
            printf("Enter value in Hexadecimal mode\n");
            scanf("%hx", &input_val);
            printf("Value = %x\n", input_val);
            break;
        case 'D':
            printf("Enter value in Decimal mode\n");
            scanf("%hd", &input_val);
            printf("Value = %d\n", input_val);
            break;
        default:
            break; 
    }
   
    return input_val;
   

}


void print_bases (short input_val, char mode) // print out base values and str for mode
{
    char modestring[4]= "   ";
    
    //Set mode string based on mode
    switch(mode)
    {
        case 'D':
            strcpy(modestring, "Dec");
            break;
        case 'H':
            strcpy(modestring, "Hex");
            break;
        case 'O':
            strcpy(modestring, "Oct");
            break;
        default:
            break;
    }
    


    printf("****************************************\n");
    printf("*  Base Values:        Input Mode: %s *\n",modestring); //modestring not correctly converting
    printf("*    Hex     :  %04hX                   *\n",input_val);
    printf("*    Octal   :  %06ho                 *\n",input_val);
    printf("*    Decimal :  %-6hd                 *\n",input_val);
    printf("****************************************\n");
    printf("\n"); 

}





char print_menu (void) // print menu; get option until valid; return option
{
    
    char mode= 'D';
    char input[3];
    int valid = 0; 

while (!valid){
    printf("Please select one of the following options:\n"); //Keep showing until valid input
    printf("\n");
    printf("O  Octal Mode\n");
    printf("H  Hexadecimal Mode\n");
    printf("D  Decimal Mode\n");
    printf("\n");
    printf("C  Clear Value\n");
    printf("S  Set Value\n");
    printf("\n");
    printf("Q  Quit\n");
    printf("\n");
    printf("Option: ");
    scanf("%s", input);
    printf("%s\n",input);


/// check if valid
    mode = toupper(input[0]);
    valid = 1;
    char valid_input[7] = "OHDCSQ";
    if (strlen(input)!= 1|| !strchr(valid_input, mode)) 
    {
        printf("Invalid input: %s\n",input);
        valid = 0; 

    }
    }
    return mode;

                }

int main (void) // main menu loop; execute option or call
// appropriate function
{  // How do I pass mode to this function
    int quit= 0; 
    short input_val = 0; 
    char mode = 'D';

    while (!quit)
    {   print_bases(input_val,mode);

        switch(print_menu())
        {
            case 'O':
                mode='O';
                printf("Mode: Octal\n");
                break;
            
            case 'H':
                printf("Mode: Hexadecimal\n"); 
                mode='H';
                break;
            case 'D':
                printf("Mode: Decimal\n");
                mode='D';
                break;
            case 'C': 
                input_val = 0;
                break;
            case 'S':
                input_val = get_operand(mode);
                print_bases(input_val,mode);
                break;
            case 'Q': 
                quit = 1;
                break;
            default:
                break;  
        

                }
                }
                return 0;}
    
    


