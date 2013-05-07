/**
 *
 *  StreaMe is a cross-platform live streaming broadcasting client, written in C++, using QT and FFMPEG library.
 *  Copyright (C) 2013, Benoit Brayer, Nans Plancher, Romaric Delaunoy.
 *  This program is free software: you can redistribute it and/or modify it under the terms of
 *  the GNU General Public License as published by the Free Software Foundation,
 *  either version 3 of the License, or (at your option) any later version.
 *  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License along with this program.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#ifndef RENAMEPROJECTWINDOW_H
#define RENAMEPROJECTWINDOW_H

#include <QWidget>
#include "controller.h"

namespace Ui {
class RenameProjectWindow;
}

class RenameProjectWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit RenameProjectWindow(Controller* controller, QWidget *parent = 0);
    ~RenameProjectWindow();
    Controller* getController();
    void setController(Controller* controller);

private:
    Ui::RenameProjectWindow *ui;
    Controller* controller;

public slots:
    void okPushButtonClicked();
    void cancelPushButtonClicked();
};

#endif // RENAMEPROJECTWINDOW_H
