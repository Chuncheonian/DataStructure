#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"

// Photo Content information class
class MusicContent : public MultimediaContent {
private:
  string    m_album;         // Photo album
  string    m_genre;

public:
  // default constructor.
  MusicContent() {
    m_album = "";
    m_genre = "";
  }

  // MusicContent(MultimediaContent &_mc) {
  //   SetName(_mc.GetName());
  //   SetTime(_mc.GetTime());
  //   SetCharacter(_mc.GetCharacter());
  //   SetLocation(_mc.GetLocation());
  //   SetEventName(_mc.GetEventName());
  //   m_condition = 1;
  //   m_viewNumber = 0;
  // }

  // default destructor.
  ~MusicContent() {}

  void Play() override {
    MultimediaContent::DisplayRecordOnScreen();
    cout << endl;
  }

  /**
   * @brief   Get album
   * @pre     album is set
   * @post    None.
   * @return  album
   */
  string GetAlbum() const { return m_album; }

  /**
   * @brief   Get genre
   * @pre     genre is set
   * @post    None.
   * @return  genre
   */
  string GetGenre() const { return m_genre; }

  /**
   * @brief   Set album
   * @pre     None.
   * @post    album is set.
   * @param   _album album
   */
  void SetAlbum(int _album) { m_album = _album; }

  /**
   * @brief   Set genre
   * @pre     None.
   * @post    genre is set.
   * @param   _genre genre
   */
  void SetGenre(string _genre) { m_genre = _genre; }

  /**
   * @brief   Set content record.
   * @pre     None.
   * @post    Content record is set.
   * @param   _album     album
   * @param   _genre genre
   */
  void SetRecord(int _album, string _genre) {
    SetAlbum(_album);
    SetGenre(_genre);
  }

  /**
   * @brief   Display album on screen.
   * @pre     album is set.
   * @post    album is on screen.
   */
  void DisplayAlbumOnscreen() { cout << "\tAlbum: " << m_album; }

  /**
   * @brief   Display genre on screen.
   * @pre     genre are set.
   * @post    genre are on screen.
   */
  void DisplayGenreOnscreen() { cout << "\tGenre: " << m_genre; }

  /**
   * @brief   Display a content record on screen.
   * @pre     content record is set.
   * @post    content record is on screen.
   */
  void DisplayRecordOnScreen() {
    DisplayAlbumOnscreen();
    DisplayGenreOnscreen();
  }

  /**
   * @brief   Set album from keyboard.
   * @pre     None.
   * @post    album is set.
   */
  void SetAlbumFromKB();

  /**
   * @brief   Set genre from keyboard.
   * @pre     None.
   * @post    genre is set.
   */
  void SetGenreFromKB();

  /**
   * @brief   Set content record from keyboard.
   * @pre     None.
   * @post    content record is set.
   */
  void Read() override;

  /**
   * @brief   Assign content record to another.
   * @pre     right MusicContent class should be initialized.
   * @post    content record in left MusicContent class is set.
   * @param   _data target MusicContent for assigning.
   */
  void operator=(const MusicContent &_data);

  /**
   * @brief   Compare corresponding condition in two MusicContent class
   * @pre     Two MusicContent class should be initialized.
   * @post    None.
   * @param   _data target MusicContent for comparing.	
   * @return  Return true If Two member variables corresponding Condition are the same, Otherwise return false.
   */
  bool operator==(const MusicContent &_data);

  /**
   * @brief   Compare two MusicContent by member variable corresponding Condition.
   * @pre     Two MusicContent should be initialized.
   * @param   data  target item for comparing.
   * @return  Return true If member variable corresponding Condition is smaller than member variable of _data, Otherwise return false.
   */
  bool operator<(MusicContent &_data);

  /**
   * @brief   Compare two MusicContent by member variable corresponding Condition.
   * @pre     Two MusicContent should be initialized.
   * @param   data  target item for comparing.
   * @return  Return true If member variable corresponding Condition is bigger than member variable of _data, Otherwise return false.
   */
  bool operator>(MusicContent &_data);

  /**
   * @brief   Print record.
   * @pre     MusicContent class should be initialized.
   * @post    content record is on screen.
   * @param   cout  ostream instance
   * @param   _data target MusicContent for printing.
   */
  friend ostream &operator<<(ostream &cout, const MusicContent &_data) {
    cout << "\t[ Content name: " << _data.m_contentName;
    cout << ", Content type: " << _data.m_contentType;
    cout << ", Create time: " << _data.m_createTime;
    cout << ", Character: " << _data.m_character;
    cout << ", location: " << _data.m_location;
    cout << ", Event name: " << _data.m_eventName;
    cout << ", Number of view: " << _data.m_viewNumber;
    cout << ", Condition(1. createTime, 2. contentName, 3. viewNumber): " << _data.m_condition;
    cout << ", Album: " << _data.m_album;
    cout << ", Genre: " << _data.m_genre << " ]";
    return cout;
  }

  /**
   * @brief   Input record.
   * @pre     None.
   * @post    content record is initialized.
   * @param   cin   istream instance
   * @param   _item target MusicContent for Input.
   */
  friend istream& operator>>(istream& cin, MusicContent& _item) {
    cout << "\n\tEnter content name: ";
    cin >> _item.m_contentName;
    cout << "\tEnter content type(ex> 1: Photo, 2: Video):";
    cin >> _item.m_contentType;
    cout << "\tEnter create time: ";
    cin >> _item.m_createTime;
    cout << "\tEnter character: ";
    cin >> _item.m_character;
    cout << "\tEnter location: ";
    cin >> _item.m_location;
    cout << "\tEnter event name: ";
    cin >> _item.m_eventName;
    cout << "\tEnter number of view: ";
    cin >> _item.m_viewNumber;
    cout << "\tEnter album: ";
    cin >> _item.m_album;
    cout << "\tEnter genre: ";
    cin >> _item.m_genre;
    return cin;
  }
};