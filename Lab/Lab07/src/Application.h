#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Main Item Type.
#include "MultimediaContent.h"
#include "MusicContent.h"
#include "PhotoContent.h"
#include "VideoContent.h"

// Data Structure.
#include "SortedDoublyLinkedList.h"

// Application Class for item management simply.
class Application {
private:
  ifstream                                    m_inFile;         // input file descriptor.
  ofstream                                    m_outFile;        // output file descriptor.
  int                                         m_command;        // current command number.

  SortedDoublyLinkedList<MultimediaContent*>  m_masterList;     // Multimedia Content List.

public:
  // default constructor.
  Application() {
    m_command = 0;
  }

  // default destructor.
  ~Application() {}

  /**
   * @brief   Program driver.
   * @pre     Program is started
   * @post    Program is finished.
   */
  void Run();

  /**
   * @brief   Display command on screen and Get a input from keyboard.
   * @pre     None.
   * @post    None.
   * @return  User's command.
   */
  int GetCommand();


  //  @@ Multi-Content Functions @@

  /**
   * @brief   Add new record into masterList.
   * @pre     masterList should be initialized.
   * @post    new record is added into the masterlist, and
   *          If new event name is input, It is added to the eventList with Primary Key of MC, else If it already exists, add the Primary Key of MC to the eventList.
   *          If new character is input, It is added to the characterList with Primary Key of MC, else If it already exists, add the Primary Key of MC to the characterList.
   *          If new location is input, It is added to the locationList with Primary Key of MC, else If it already exists, add the Primary Key of MC to the locationList.
   * @return  return 1 if this function works well, oterwise return 0.
   */
  int Read();

  /**
   * @brief   Display all MultimediaContents in the list in screen.
   * @pre     None.
   * @post    None.
   */
  void Play();
};