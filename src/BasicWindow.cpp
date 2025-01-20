#include"BasicWindow.h"


BasicWindow::BasicWindow(const sf::Vector2f size, const std::string& windowName)
	:m_windowSize(size), m_window(sf::VideoMode(unsigned(m_windowSize.x), unsigned(m_windowSize.y)), windowName)
{
	//m_window.clear();
	//m_window.display();
}


bool BasicWindow::isOpen() const
{
	return m_window.isOpen();
}

void BasicWindow::close()
{
	if(isOpen())
		m_window.close();
}

void BasicWindow::clear()
{
	m_window.clear();
}

void BasicWindow::display()
{
	m_window.display();
}