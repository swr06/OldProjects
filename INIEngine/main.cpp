#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>

using namespace std ;

bool chk_IllegalChars(char c)
{
    string illegal_c = {"!@#$%^&*()-+~`<,>.:;?/""''={}[]| "}  ;
    bool retval = true ;

    for (int i = 0 ; i <= illegal_c.size() ; i++)
    {
        if (c == illegal_c[i])
        {
            retval = false ;

            break ;
        }
    }

    return retval ;
}


fstream& GotoLine(std::fstream& file, unsigned int num)
{
    file.seekg(std::ios::beg) ;

    for(int i = 0 ; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    return file;
}

string ReadINIFile(string file_path, string ini_label)
{
    int read_point = -1 ;
    bool op_chk = false ; // used to check if the equals operator exists
    long line_no = 0 ;
    fstream file ;
    string line ;
    string var_name ;
    string var_val ;
    stringstream ret_val ;

    file.open(file_path) ;

    if (file.good())
    {
        while (getline(file,line))
        {
            line_no++ ;

            if (line[0] != '#' && line[1] != '#' && !line.empty())
            {
                for (int i = 0 ; i < line.size() ; i++)
                {
                    if (line[i] == ' ' && line[i + 1] == '=' && line[i + 2] == ' ')
                    {
                        read_point = i + 3 ;
                        op_chk = true ;

                        break ;
                    }

                    else if ((line[i] == ' ' && line[i + 1] == '=') ||
                             (line[i] == '=' && line[i + 1] == ' '))
                    {
                        read_point = i + 2 ;
                        op_chk = true ;

                        break ;
                    }

                    else if (line[i] == '=')
                    {
                        read_point = i + 1 ;
                        op_chk = true ;

                        break ;
                    }

                    else
                    {
                        if (chk_IllegalChars(line[i]) == true)
                        {
                            var_name.push_back(line[i]) ;
                        }
                    }
                }

                if (read_point != -1 && op_chk == true)
                {
                    for (int i = read_point ; i < line.size() ; i++)
                    {
                        if (chk_IllegalChars(line[i]) == true)
                        {
                            var_val.push_back(line[i]) ;
                        }
                    }
                }

                else
                {
                    ret_val << "\nReading error in line " << line_no << " of " << file_path ;

                    return ret_val.str() ;
                }

                if (ini_label == var_name)
                {
                    var_name.erase(var_name.begin(),var_name.end()) ;
                    line.erase(line.begin(),line.end()) ;
                    file.close() ;
                    return var_val ;
                }

                else
                {
                    var_name.erase(var_name.begin(),var_name.end()) ;
                    var_val.erase(var_val.begin(),var_val.end()) ;
                    line.erase(line.begin(),line.end()) ;
                    op_chk = false ;
                    read_point = -1 ;
                }
            }
        }
    }

    else
    {
        ret_val << file_path << " Not Found" ;

        return ret_val.str() ;
    }

    return "\nFatal error" ;
}

bool ChangeINIVal(string file_path, string ini_label, string ini_newval)
{
    int read_point = -1 ;
    int write_size = 0 ;
    long seek_pos = 0 ;
    bool op_chk = false ; // used to check if the equals operator exists
    long line_no = 0 ;
    fstream file ;
    string line ;
    string var_name ;
    stringstream ret_val ;

    file.open(file_path) ;

    if (file.good())
    {
        while (getline(file,line))
        {
            line_no++ ;

            if (line[0] != '#' && line[1] != '#' && !line.empty())
            {
                for (int i = 0 ; i < line.size() ; i++)
                {
                    if (line[i] == ' ' && line[i + 1] == '=' && line[i + 2] == ' ')
                    {
                        read_point = i + 3 ;
                        op_chk = true ;

                        break ;
                    }

                    else if ((line[i] == ' ' && line[i + 1] == '=') ||
                             (line[i] == '=' && line[i + 1] == ' '))
                    {
                        read_point = i + 2 ;
                        op_chk = true ;

                        break ;
                    }

                    else if (line[i] == '=')
                    {
                        read_point = i + 1 ;
                        op_chk = true ;

                        break ;
                    }

                    else
                    {
                        if (chk_IllegalChars(line[i]) == true)
                        {
                            var_name.push_back(line[i]) ;
                        }
                    }
                }


                if (ini_label == var_name && op_chk == true && read_point != -1)
                {
                    write_size = line.size() - read_point ;
                    seek_pos = seek_pos + read_point ;
                    seek_pos = seek_pos + line_no + 2 ;
                    file.seekp(seek_pos,ios::beg) ;
                    file.write(ini_newval.c_str(),ini_newval.size()) ;

                    if (write_size > ini_newval.size())
                    {
                        cout << "\nGREATER" ;
                        file.write(" ",write_size - ini_newval.size()) ;
                    }

                    file.close() ;

                    return true ;
                }

                else
                {
                    var_name.erase(var_name.begin(),var_name.end()) ;
                    op_chk = false ;
                    read_point = -1 ;
                }
            }

            seek_pos = seek_pos + line.size() ;
            line.erase(line.begin(),line.end()) ;
        }
    }

    else
    {
        return false ;
    }

    return false ;
}

int main()
{
    cout << endl << ChangeINIVal("file.ini","variable2","41") ;

    return 0 ;
}




