#include <string>
#include <vector>
#include <QApplication>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QList>
#include <QStringList>
#include "window.h"
#include "booster.h"

namespace BoosterApp {
 
Window::Window(QWidget *parent) : QWidget(parent)
{
	// Set size of the window
	setFixedSize(1000, 1000);

	// Create and position the button
	m_button = new QPushButton("Erkki", this);
	m_button->setGeometry(10, 10, 80, 30);

        m_button->setCheckable(true);
        connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
        connect(this, SIGNAL (counterReached()), QApplication::instance(), SLOT (quit()));
        QTreeWidget* qtw = new QTreeWidget(this);
        qtw->setColumnCount(1);
        QList<QTreeWidgetItem*> items;

        for (int i = 0; i < 10; ++i)
                items.append(new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr), QStringList(QString("item: %1").arg(i))));
        qtw->insertTopLevelItems(0, items);
        // p_boosters.push_back(new Booster(this));
        // p_boosters.push_back(new Booster(this));
        // p_boosters.push_back(new Booster(this));
        // p_boosters.push_back(new Booster(this));
        // p_boosters.push_back(new Booster(this));
        // p_boosters.push_back(new Booster(this));
}

void Window::slotButtonClicked(bool checked)
{
    if (checked) {
        m_button->setText("Checked");
    } else {
        m_button->setText("Hello World");
    }
    m_counter ++;

    if (m_counter == 10) { emit counterReached(); }
}

} // namespace
