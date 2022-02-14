#include <iostream>
#include <string>

class openfile{
    private:
        FILE* f;
    public:
        openfile(const char *filename){
            f = fopen(filename, "r" );
        }
        ~openfile(){
            fclose(f);
        }

        int getchar(){
            int c = getc(f);
            if ( c == '$' )
            {
                return -1;
            }
            return c;
        }
        
        bool isopen() const{
            if(!f)
            {
                std::cout <<"could not open the file\n";
                return false;
            }
            return true;
        }

};

int main(int argc, char* argv[])
{
    const char *filename = "myfile.in";
    openfile op(filename);
    if (op.isopen()){    
        int c;
        int line = 1;
        while (c != EOF){
            c = op.getchar();
            if (c == '\n'){
                // std::cout << '\n';
                line++;
            }
            else if (c == -1){
                std::cout << "illegal dollar sign in line " << line << "\n";
            }
            // else{
            //     std::cout << c;
            // }
        }
    }
    else {
        std::cout << "could not open the file\n";
    }   
    return 0;
}