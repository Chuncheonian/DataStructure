#include "Application.h"

// Program driver.
void Application::Run() {
  while (1) {
    m_command = GetCommand();

    switch (m_command) {
      case 1: // Add new record into masterList.
        Read();
        break;
    case 2: // Display all MultimediaContents in the list in screen.
        Play();
        break;
    case 0: // quit
        return;
    default:
      cout << "\tIllegal sellection...\n";
      break;
    }
  }
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand() {
  int command;
  cout << endl << endl;
  cout << "\t   ----- Main Command ----- " << endl;
  cout << "\t1 : Insert content" << endl;
  cout << "\t2 : Display all content" << endl;
  cout << "\t0 : Quit " << endl;

  cout << endl << "\tChoose a Command--> ";
  cin >> command;
  cout << endl;

  return command;
}

// Add new record into masterList.
int Application::Read() {
  MultimediaContent* p_mainContent;
  int InputGenre = 0;
  cout << "\tInput Content type(1. Music, 2. Photo, 3.Video): ";
  cin >> InputGenre;
  switch(InputGenre) {
    case 1:
      p_mainContent = new MusicContent();
      break;
    case 2:
      p_mainContent = new PhotoContent();
      break;
    case 3:
      p_mainContent = new VideoContent();
      break;
    default:
      cout << "\tIllegal selection...\n";
      return 0;
  }

  p_mainContent->Read();
  m_masterList.Add(p_mainContent);

  return 1;
}

// Display all MultimediaContents in the list in screen.
void Application::Play() {
	DoublyIterator<MultimediaContent*> iter(m_masterList);
	cout << "\n\t--Current list--" << endl;

	while (iter.NotNull()) {
    iter.GetCurrentNode().data->Play();
		iter.Next();
	}
}
