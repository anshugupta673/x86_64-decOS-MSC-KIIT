#include "lib.h"
#include "console.h"
//#include "stdint.h"

static void cmd_calc(void)
{
    printf("hi i can calculate\n");
} 

static void cmd_fetch(void)
{
    uint64_t t;
    
    printf("Welcome to x86_64-decOS @ MSC-KIIT\nv1.0.0\n");
} 

static void cmd_get_total_memory(void)
{
    uint64_t total;
    
    total = get_total_memoryu();
    printf("Total Memory is %dMB\n", total);
}

static int read_user_name(char *user_name)
{
    char ch[2] = { 0 };
    int buffer_size = 0;

    while (1) {
        ch[0] = keyboard_readu();
        
        if (ch[0] == '\n' || buffer_size >= 80) {
            printf("%s", ch);
            break;
        }
        else if (ch[0] == '\b') {    
            if (buffer_size > 0) {
                buffer_size--;
                printf("%s", ch);    
            }           
        }          
        else {     
            user_name[buffer_size++] = ch[0]; 
            printf("%s", ch);        
        }
    }

    return buffer_size;
}

static int read_cmd(char *buffer)
{
    char ch[2] = { 0 };
    int buffer_size = 0;

    while (1) {
        ch[0] = keyboard_readu();
        
        if (ch[0] == '\n' || buffer_size >= 80) {
            printf("%s", ch);
            break;
        }
        else if (ch[0] == '\b') {    
            if (buffer_size > 0) {
                buffer_size--;
                printf("%s", ch);    
            }           
        }          
        else {     
            buffer[buffer_size++] = ch[0]; 
            printf("%s", ch);        
        }
    }

    return buffer_size;
}

static int parse_cmd(char *buffer, int buffer_size)
{
    int cmd = -1;

    if (buffer_size == 8 && (!memcmp("totalmem", buffer, 8))) {
        cmd = 0;
    }

    if(buffer_size == 5 && (!memcmp("fetch", buffer, 5))) {
        cmd = 0;
    }

    if(buffer_size == 5 && (!memcmp("bc -l", buffer, 5))) {
        cmd = 0;
    }

    return cmd;
}


static void execute_cmd(int cmd, char *buffer, int string_return)
{ 
    // CmdFunc cmd_list[1];
    // if(buffer[0] == 't' && buffer[1] == 'o'){
    //     CmdFunc cmd_list[1] = {cmd_get_total_memory};  
    // }
    

    
    CmdFunc cmd_list[1] = {cmd_get_total_memory};
    //CmdFunc cmd_list[2] = {cmd_fetch};
    //CmdFunc cmd_list[2] = {cmd_calc};



    // CmdFunc cmd_list[0]();
    // if(string_return == 3) {
    //     cmd_list[1] = {cmd_fetch};   
    // }

    if (cmd == 0) {       
        cmd_list[0]();
    }
}

//string comparisons for input
//ls : 1
//totalmem : 2
//decOSfetch : 3

int main(void)
{
    char buffer[80] = { 0 };
    int buffer_size = 0;
    int cmd = 0;

    int cont = 0;

    while (1) {

        if(cont == 0){
            printf("Enter username : "); char user_name[80] = {0};
            int userbuffsize = read_user_name(user_name);
            cont =1;
        }

        printf("x86_64-decOS @ MSC KIIT $ ~ ");
        buffer_size = read_cmd(buffer);

        //test-check if all the directories are acccessed by get root dir func
        int ls = 0;
        if(buffer[0] == 'l' && buffer[1] == 's') {
            printf("lib\nuser1\nuser2\nuser3\nimg\nhome\ndecOS\n");
            ls = 1;
        }

        if (buffer_size == 0) {
            continue;
        }
        
        cmd = parse_cmd(buffer, buffer_size);
        
        if (cmd < 0 && ls == 0) {
            printf("Command Not Found!\n");
        }
        else {
            int x;
            int string_return = 100;
            if(buffer[0] == 'd' && buffer[1] == 'e'){
                string_return = 3;
                //scanf("%d", &x);
            } 

            execute_cmd(cmd, buffer, string_return);             
        }            
    }

    return 0;
}

