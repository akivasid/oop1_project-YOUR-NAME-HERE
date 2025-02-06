#include"BasicWindow.h"


BasicWindow::BasicWindow(const sf::Vector2f size, const std::string& windowName, const std::string& musicFile)
	:m_windowSize(size), m_window(sf::VideoMode(unsigned(m_windowSize.x), unsigned(m_windowSize.y)), windowName)
{
	if(!m_backgroundMusic.openFromFile(musicFile))
		std::cerr << "failed to open file " << musicFile;
	m_backgroundMusic.play();
}


bool BasicWindow::isOpen() const
{
	return m_window.isOpen();
}

void BasicWindow::close()
{
	m_window.close();
	stopMusic();
}

void BasicWindow::clear()
{
	m_window.clear();
}

void BasicWindow::display()
{
	m_window.display();
}

void BasicWindow::stopMusic()
{
	m_backgroundMusic.stop();
}

void BasicWindow::playMusic()
{
	m_backgroundMusic.play();
}