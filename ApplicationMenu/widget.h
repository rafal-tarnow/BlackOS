#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <string>
#include <vector>

using namespace std;


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    vector<string> list_directory(const char * directoryName);
    string get_file_extension(const string& FileName);
    Ui::Widget *ui;
    string application_menu_path = "/usr/share/applications/";
};

#endif // WIDGET_H
