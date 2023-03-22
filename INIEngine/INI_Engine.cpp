#include "INI_Engine.h"

int ini_GetNoLines(string file)
{
    int line_no = 1 ;
    fstream ofile ; // opened file
    string store ;

    ofile.open(file.c_str()) ;

    if (ofile.good())
    {
        while (getline(ofile,store))
        {
            if (ofile.eof())
            {
                break ;
            }

            line_no++ ;
        }
    }

    else
    {
        return -1 ;
    }

    ofile.close() ;
    return line_no ;
}
/*
bool chk_IllegalChars(char c)
{
    string illegal_c = {"!@#$%^&*()-+=~`<,>.:;?/""''{}[]|"}  ;
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

string ini_ReadINIFile(string file_path, string file_label)
{
    int read_point = -1 ;
    fstream file ;
    string line ;
    string var_name ;
    string var_val ;

    file.open(file_path) ;

    if (file.good())
    {
        while (getline(file,line))
        {
            if (file.eof())
            {
                break ;
            }

            if (line[0] != '#' && line[1] != '#')
            {
                for (int i = 0 ; i < line.size() ; i++)
                {
                    if (chk_IllegalChars(line[i]) == true)
                    {
                        if (line[i] == ' ' && line[i + 1] == '=' && line[i + 2] == ' ' && line[i + 3] != ' ')
                        {
                            read_point = i + 3 ;

                            break ;
                        }

                        else if ((line[i] == ' ' && line[i + 1] == '=' && line[i + 2] != ' ') ||
                                 (line[i] == '=' && line[i + 1] == ' ' && line[i + 2] != ' '))
                        {
                            read_point = i + 2 ;


                            break ;
                        }

                        else if (line[i] == '=' && line[i + 1] != ' ')
                        {
                            read_point = i + 1 ;

                            break ;
                        }

                        else
                        {
                            var_name.push_back(line[i]) ;
                        }
                    }
                }
            }
        }

        if (read_point != -1)
        {
            for (int i = read_point ; i < line.size() ; i++)
            {
                if (chk_IllegalChars(line[i]) == true)
                {
                    var_val.push_back(line[i]) ;
                }

                else
                {
                    break ;
                }
            }
        }

        else
        {
            return 0 ;
        }

        if (file_label == var_name)
        {
            return var_val ;
        }
    }

    else
    {
        return 0 ;
    }
}*/


