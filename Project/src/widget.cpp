#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <QtCore>
#include <vector>
#include <map>
#include "generateAuditFile.h"
#include "cpl.h"
#include "opl.h"
#include "countVote.h"
#include "countVoteOPL.h"
#include "displayWinner.h"
#include "displayWinnerCPL.h"
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    g = NULL;
    cpl = NULL;
    count = NULL;
    d = NULL;
    opl = NULL;
    countopl = NULL;
    dopl = NULL;
}

Widget::~Widget()
{
    delete ui;
    delete g;
    delete cpl;
    delete count;
    delete d;
    delete opl;
    delete countopl;
    delete dopl;
}


void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../", "CSV(*.CSV)");
    std::string filename = path.toUtf8().constData();
    ifstream in(filename);
    if (!in) {
        ui -> textEdit -> setText("cannot open the file \n");
        return;
    }
    ui -> textEdit -> setText("Succesfully read the file: " + QString::fromStdString(filename)+ "\n");
    g = new GenerateAuditFile(in);
    string type = g->get_type_of_election();
    if (type == "CPL") {
            cpl = new CPL(in);
            count = new CountVote(cpl);
            std::vector<string> candidate = cpl->get_candidate();
            map<char,int> result = count->get_vote_count();
            d = new DisplayWinnerCPL(result, candidate);
    } else {
        opl = new OPL(in);
            countopl = new CountVoteOPL(opl);
            map<std::string,int> resultopl = countopl->get_vote_count();
            dopl = new DisplayWinner(resultopl);
    }

}

void Widget::on_buttonRun_clicked() {
    string type = g->get_type_of_election();
    if (type == "CPL") {
        std::string num = to_string(cpl->get_number_of_parties());
        std::string set = to_string(cpl->get_number_of_seat());
        std::string num_can = to_string(cpl->get_number_of_candidate());
        std::string ballot = to_string(cpl->get_number_of_ballot());
        QString text = "The type of election is: CPL\n";
        text += "The numer of parties is: ";
        text += QString::fromStdString(num);
        text += "\nThe numer of sets is: ";
        text += QString::fromStdString(set);
        text += "\nThe numer of ballots is: ";
        text += QString::fromStdString(ballot);
        text += "\nThe numer of candidates is: ";
        text += QString::fromStdString(num_can);
        int winner = d->display();
        map<char,int> result = count->get_vote_count();
        int count = 0;
        char winner_party;
        for (map<char, int>::iterator it = result.begin(); it != result.end(); it++) {
            if(count == winner) {
                text += "\nthe winner party is ";
                text += QChar(it->first);
                text +=" with total votes ";
                text += QString::number(it->second);
                text += "\nthe party ";
                text += QChar(it->first);
                text += " has the following candidate(s):\n";
                winner_party = it->first;
                break;
            }
            count ++;
        }
        vector<string> candidate = cpl->get_candidate();
        for (int i=0; i<candidate.size(); i++) {
              int index = candidate[i].find(',');
              if (candidate[i].at(index+1) == winner_party) {
                text += QString::fromStdString(candidate[i]);
              }
        }
        ui -> textEdit -> setText(text);
    } else {
        QString text = "The type of election is: OPL\n";
        std::string set = to_string(opl->get_number_of_seat());
        std::string num_can = to_string(opl->get_number_of_candidate());
        std::string ballot = to_string(opl->get_number_of_ballot());
//        /******************display result*****************************/
        text += "The numer of sets is: " ;
        text += QString::fromStdString(set);
        text += "\nThe numer of ballots is: ";
        text += QString::fromStdString(ballot);
        text += "\nThe numer of candidates is: ";
        text += QString::fromStdString(num_can);
        std::string result = dopl->display();
        text += QString::fromStdString(result);
        ui -> textEdit -> setText(text);
    }

}


void Widget::on_buttonWrite_clicked(){
    QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");
    string filename = path.toUtf8().constData();
    string type = g->get_type_of_election();
    if (type == "CPL") {
        cpl ->generate_audit_file(filename);
    } else {
        opl ->generate_audit_file(filename);
    }

}
