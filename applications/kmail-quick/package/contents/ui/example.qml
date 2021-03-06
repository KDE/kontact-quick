/*
 * Copyright (C) 2015 Michael Bohlender <michael.bohlender@kdemail.net>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

import org.kde.akonadi2.mail 1.0

Item {
    id: root

    MailList {
        id: mailList

        query: "Some Query"

    }

    Button {
        id: button

        anchors {
            top: parent.top
            right: parent.right
            left: parent.left
        }

        text: "add mail"

        onClicked: mailList.addMail("test test test");
    }

    ListView {

        anchors {
            top: button.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        model: mailList.model

        delegate: Label {

            text: model.subject
        }
    }
}