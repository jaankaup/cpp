#include "booster.h"

Booster::Booster(QWidget *parent) : QWidget(parent)
{
	// Set size of the window
	setFixedSize(500, 100);

        p_label = new QLabel("Erkki", this);
	// p_label->setFixedSize(400, 20);
        //p_label = std::make_unique<QLabel>("Erkki");
	// p_label2->setFixedSize(400, 20);

	// Create and position the button
	// m_button = new QPushButton("Erkki", this);
	// m_button->setGeometry(10, 10, 80, 30);

        // m_button->setCheckable(true);
        // connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
        // connect(this, SIGNAL (counterReached()), QApplication::instance(), SLOT (quit()));
}
