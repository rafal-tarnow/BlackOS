#include "widget.h"
#include "ui_widget.h"
#include <sys/types.h>
#include <dirent.h>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    vector<string> file_list;
    file_list = list_directory(application_menu_path.c_str());

    for(int i = 0; i < file_list.size(); i++){
        cout << file_list[i] << endl;
    }
    cout.flush();
}

Widget::~Widget()
{
    delete ui;
}


vector<string> Widget::list_directory(const char * directoryName){
    struct dirent * plik;
    DIR * sciezka;

    string file_name;
    vector<string> files_list;

    if(( sciezka = opendir( directoryName ) ) ) {
        while(( plik = readdir( sciezka ) ) )
        {
            if(plik->d_type != DT_DIR) //check is file
            {
                file_name = plik->d_name;
                if("desktop" == get_file_extension(file_name)){  // check extension
                       files_list.push_back(file_name);
                }

            }
        }

        closedir( sciezka );
    }
    else
        cout << "Error reading from " << directoryName;

    return files_list;
}

string Widget::get_file_extension(const string& FileName)
{
    if(FileName.find_last_of(".") != string::npos)
        return FileName.substr(FileName.find_last_of(".")+1);
    return "";
}
