/**
 * @file widget.h
 *
 * @copyright csci5801 team26, All rights reserved.
 */
#ifndef WIDGET_H
#define WIDGET_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <QWidget>
#include "generateAuditFile.h"
#include "cpl.h"
#include "opl.h"
#include "countVote.h"
#include "countVoteOPL.h"
#include "displayWinner.h"
#include "displayWinnerCPL.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the Widget.
 *
 *  This is a static call, not requiring an instance to invoke the method.
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a Widget.
     *
     * @param[in] QWidget *
     *
     * @return pointer parent to QWidget.
     */
    Widget(QWidget *parent = nullptr);
    ~Widget();
    GenerateAuditFile * g;
    CPL * cpl;
    CountVote *count;
    DisplayWinnerCPL * d;
    OPL * opl;
    CountVoteOPL *countopl;
    DisplayWinner * dopl;

private slots:
    void on_buttonRead_clicked();
    void on_buttonWrite_clicked();
    void on_buttonRun_clicked();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
