#ifndef CICOPUSHBUTTON_H
#define CICOPUSHBUTTON_H
#include <QPushButton>
#include <QStyleOptionButton>
#include <QIcon>

class CicoPushButton : public QPushButton
{
public:
    explicit CicoPushButton(QWidget * parent = Q_NULLPTR);
    explicit CicoPushButton(const QString &text, QWidget *parent = Q_NULLPTR);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    void updateIcon(QStyleOptionButton &pushbutton);

private:
    bool m_iconCached;
    QIcon m_downIcon;
};

#endif // CICOPUSHBUTTON_H
