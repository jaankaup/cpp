#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;

namespace Yeah {

class Window : public QWidget
{
 public:
  explicit Window(QWidget *parent = 0);
 private:
 QPushButton *m_button;
};

} // namespace

#endif // WINDOW_H
