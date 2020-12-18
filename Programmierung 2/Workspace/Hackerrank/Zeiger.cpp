/*******************************************************************************
 *
 *   Datei      : Liste2.cpp
 *
 *   Autor      : Dipl.-Ing. Ralf Koller @HSOS
 *                r.koller@hs-osnabrueck.de
 *                Hochschule Osnabrueck
 *                Fakultaet Ingenieurwissenschaften und Informatik
 *
 *   Thema      : Zwischentest Programierung 2 TI -> Liste
 *
 *   Version 1  : 11.02.2020
 *
 *   To Do      :
 *
 *
 ******************************************************************************/
/*
                              Aufgabenstellung
                              ================
  Die Klasse Liste verwaltet eine einfach verkettete Liste von Objekten vom Typ
  ListenElement, gemaess der im Source Code befindlichen Skizze.

  ----------------
  | listenwurzel |
  ----------------
    |
    |
    v
  ----------     ----------     ----------     ----------
  | inhalt | --> | inhalt | --> | inhalt | --> | inhalt | --> NULL
  ----------     ----------     ----------     ----------

 (Skizze zeigt beispielhaft eine Liste mit 4 Elementen)

 Das Listenelement verwaltet:
                - Eine Variable "inhalt" vom Typ int
                - Eine Variable "nachfolger" vom Typ Zeiger auf Listenelement

 Implementieren Sie an der im Source Code vorgesehenden Position die Methode:

 void Liste::einfuegen_vor (int bezug, int wert);

 Die Methode soll folgende Funktionalitaeten enthalten:
 - Einfuegen eines zu erzeugenden ListenElement-Objektes mit inhalt=wert vor
   dem ListenElement-Objekt, mit inhalt==bezug.

 - Ist die Liste leer, so ist das neue Element der Anfang der Liste.

 - Existiert ein solches Listenelement-Objekt mit dem inhalt==bezug nicht, soll
   das neue ListenElement-Objekt vor dem ersten ListenElement-
   Objekt der Liste eingefuegt werden und es soll ein AusnahmeObjekt vom Typ
   "ListenElementExistiertNicht" mit "bezug" initialisiert und geworfen werden.

*******************************************************************************
                            Input Format:
                           --------------
 Nach der Eingabe einer Zahl mit abschliessendem "Return" startet der entspr. Test mit
 Default- bzw. fest vorgegebenen Testdaten automatisch. Mehr ist nicht zu
 veranlassen. Der jeweilige Test wird sofort durchgeführt.

Der Menuepunkt 1 stellt beim Start eine Besonderheit dar.

 1 -> Die Liste wird einfach nur mit Default- oder auch mit frei waehlbaren Parametern
      gefuellt. Mit eigenen Testdaten ist es moeglich, den Ablauf selbst zu steuern
      und so nach eigenen Wuenschen Fehler in seiner Implementation zu debuggen.
      Mit der einfachen Anwahl des Menuepunktes 1 wird der Programmpunkt mit
      Defaulteingabedaten durchgefuehrt:
            Beispiel 1:
            ------------
                Input:
                    1
               Output:
                    vor: 5 6 7 8 9 10

            Beispiel 2 mit eigenen Testdaten:
            ---------------------------------
                Input:
                    1 0;7 7;8 8;9 9;10 10;11 11;12     // mit bezug;wert
               Output:
                    vor: 12 11 10 9 8 7


 Die folgenden Menuepunkte erfordern nur die Eingabe der entspr. Aktion:

  2 ->  Test_einfuegen_vor_leereListe():          Funktionalitaet der leeren
                                                  Liste
  3 ->  Test_einfuegen_vor_einelementigeListe():  Funktionalitaet der Liste
                                                  bestehend aus einem Element
  4 ->  Test_einfuegen_vor_zweielementigeListe(): Funktionalitaet der Liste
                                                  bestehend aus zwei Elementen
  5 ->  Test_einfuegen_vor_dreielementigeListe(): Funktionalitaet der Liste
                                                  bestehend aus drei Elementen
  6 ->  TestAll: Test 2,3,4,5 werden auf einmal durchgefuehrt


*******************************************************************************
                        Was wird getestet:
                       --------------------
  2 -> Test_einfuegen_vor_leereListe():
       Der Test kontrolliert das Verhalten der Liste beim Einfuegen von Elementen,
       sofern die Liste noch leer sein sollte.

  3 -> Test_einfuegen_vor_einelementigeListe():
       Dieser Test kontrolliert das Verhalten der Liste, sofern nur ein Element
       in der Liste gespeichert sein sollte.

  4 -> Test_einfuegen_vor_zweielementigeListe():
       Hier wird das richtige Einfuegen von Objekten an unterschiedlichen
       Positionen innerhalb einer Liste, bestehend aus genau zwei Elementen, getestet.

  5 -> Test_einfuegen_vor_dreielementigeListe():
       Wie unter Test 4, jedoch in einer Liste, bestehend aus genau drei Elementen.

  6 -> TestAll: Test 2,3,4,5 werden auf einmal durchgefuehrt


******************************************************************************/

#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>

using namespace std;

// Deklaration: Fehlerklasse ---------------------------------------------------

class wrong_argument {};
class ListenElementExistiertNicht {
public:
    int wert;
    ListenElementExistiertNicht(int bezug) : wert(bezug) {
    }
};

// Deklaration: ListenElement --------------------------------------------------

class ListenElement {
public:
    int inhalt;
    ListenElement* nachfolger;
};

// Deklaration: Liste ----------------------------------------------------------

class Liste {
    string name;
    ListenElement* listenwurzel;

    Liste(const Liste& orig);                             // nicht implementiert
    Liste& operator=(const Liste& rhs);                   // nicht implementiert

public:
    Liste(string);
    ~Liste();

    /* Einfuegen eines zu erzeugenden ListenElement-Objektes
     * mit inhalt=wert vor dem ListenElement-Objekt,
     * mit inhalt==bezug.
     */
  void einfuegen_vor(int bezug, int wert);

  // Abfragen
  bool empty() const;
  unsigned int size() const;

  // Textuelle Darstellung der Liste
  string toString() const;
};

Liste::Liste(string name): listenwurzel(0),name(name) {}      // die leere Liste

Liste::~Liste() {                                                  // Destruktor
  ListenElement* wanderer=listenwurzel;
  while (wanderer!=0) {
    wanderer=wanderer->nachfolger;
    delete listenwurzel;
    listenwurzel=wanderer;
  }
}

// =============================================================================
// Implementationen:
// =================
// Ab hier sollen Ihre Methoden/Funktionen implementiert werden.
// Falls noetig, bitte auch an die Deklaration oben im Klassenheader denken.
//
// Wichtig:
// --------
// Methoden, die sie zusaetzlich zu den oben angegebenen als Hilfsmethoden
// programmieren, sind ausschließlich im privaten Teil der Klasse zu vereinbaren.
//
// Ihr Programm wird erst dann vom Compiler akzeptiert, wenn Sie saemtliche
// fehlenden Teile (Methoden, Klassen etc.) vereinbart und zumindest mit
// Dummy-Funktionalitaet versehen haben.
//
// =============================================================================

//
// HIER: Eigenen Namen eintragen!
string meinName = "Nils Helming";

void Liste::einfuegen_vor(int bezug, int wert) {
    //um diesen Teil nich wiederholt zu schreiben wird zunächst das zu einfügende Element erstellt:
    //(denn wir erwarten in jedem Fall ein neues ListenElement in der Liste - selbst in den Ausnahmefällen)
    ListenElement* neuesElement = new ListenElement();
    neuesElement->inhalt = wert;
    neuesElement->nachfolger = nullptr; //nicht notwendig, wird in jedem Fall überschrieben!

    //Sonderfall - Listenwurzel wird ersetzt (Leere Liste oder *bezug* verweist auf das erste Element):
    if (this->empty() || this->listenwurzel->inhalt == bezug){
        neuesElement->nachfolger = this->listenwurzel; //bei Leerer Liste sollte dies 'nullptr' sein.
        this->listenwurzel = neuesElement;
        //nicht sicher warum, aber bei Leerer Liste soll KEIN ListenElementExistiertNicht geworfen werden?
    } else {
        //Es wird nach dem ListenElement mit dem Wert *bezug* gesucht!
        //Die Listenwurzel ist hierfür schon ausgeschlossen worden!

        ListenElement* wanderer = listenwurzel; //Liste ist nicht leer => listenwurzel != nullptr
        while(wanderer->nachfolger != nullptr){
            if(wanderer->nachfolger->inhalt == bezug){
                //wir haben unser *bezug*-Element gefunden, zwischen wanderer und dessen nachfolger wollen wir einfügen!
                neuesElement->nachfolger = wanderer->nachfolger;//VOR dem nachfolger des wanderers und...
                wanderer->nachfolger = neuesElement;//NACH dem wanderer!
                return;//wir haben erfolgreich eingefügt!
            } else
                wanderer = wanderer->nachfolger; //'wandere' ein Element weiter.
        }

        //Falls wir diese Stelle erreichen sind wir in dieser Situation:
        //(1) Die Liste war NICHT leer.
        //(2) Weder die Listenwurzel, noch eines der anderen ListenElemente haben *bezug* als inhalt.
        //Wir sollen hier das neuesElement als neue Listenwurzel einfügen und ListenElementExistiertNicht werfen.


        neuesElement->nachfolger = this->listenwurzel;
        this->listenwurzel = neuesElement;

        throw ListenElementExistiertNicht(bezug);

    }

}


/*******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *
 * AB HIER DUERFEN KEINE AENDERUNGEN VORGENOMMEN WERDEN !!!
 *
 * Zur Erfuellung der Aufgabe, ist das Verstaendnis des folgenden
 * Sourcecode nicht notwendig !!
 *
 *******************************************************************************
 *******************************************************************************
 ******************************************************************************/

/* Testfaelle (NICHT AENDERN !!!) ============================================*/

class Test_Liste {                                                 // Testklasse
  string tname;
  void trim(string& info);
public:
  void Test_einfuegen_vor_leereListe();
  void Test_einfuegen_vor_einelementigeListe();
  void Test_einfuegen_vor_zweielementigeListe();
  void Test_einfuegen_vor_dreielementigeListe();
};


// =============================================================================
// Hilfsfunktionen und Konstanten-> nichts aendern !
// =============================================================================

#define DEFAULTWERTE_VOR  "0;10 10;9 9;8 8;7 7;6 6;5"
#define DELEMITER ' '
#define TRENNER ';'

int einlesen_werte(vector<pair<int, int> > &werte, string werteString);
void fuelleListe_nach(Liste&, string);
void fuelleListe_vor(Liste&, string);
int read_para(string&);

// =============================================================================
// Main -> nichts aendern !
// =============================================================================

int main() {
    char dummy;
    int action(-1);
    string parameter="";
    Test_Liste test;                             // Objekt zum Testen der Listen

    action = read_para(parameter);
    switch (action) {
        case 1:  {
                 Liste vor("vor"); fuelleListe_vor(vor, parameter);
                 cout << vor.toString() << endl;            // vor: 5 6 7 8 9 10
                 break;
                 }
        case 2:  test.Test_einfuegen_vor_leereListe();
                 break;
        case 3:  test.Test_einfuegen_vor_einelementigeListe();
                 break;
        case 4:  test.Test_einfuegen_vor_zweielementigeListe();
                 break;
        case 5:  test.Test_einfuegen_vor_dreielementigeListe();
                 break;
        case 6:  test.Test_einfuegen_vor_leereListe();cout<<endl;
                 test.Test_einfuegen_vor_einelementigeListe(); cout<<endl;
                 test.Test_einfuegen_vor_zweielementigeListe(); cout<<endl;
                 test.Test_einfuegen_vor_dreielementigeListe(); cout<<endl;
        case 0: return (0);                                          // --> Ende
        default: cout << "Auswahl fehlerhaft!" << endl;
                 return (1);
    }
}

// =============================================================================
// Hilfsmethoden -> nichts aendern !
// =============================================================================

bool Liste::empty() const {                                    // ist Liste leer
  return (listenwurzel==0);
}

unsigned int Liste::size() const {
  unsigned int n=0;
  ListenElement* wanderer=listenwurzel;
  while (wanderer!=0) {
    n++;
    wanderer=wanderer->nachfolger;
  }
  return n;
}

std::string Liste::toString() const {                      // Name: z1 z2 z3 ...
  ostringstream sout("");
  sout << name << ": ";
  ListenElement* wanderer=listenwurzel;
  while (wanderer!=0) {
    sout << wanderer->inhalt;
    sout << " ";
    wanderer=wanderer->nachfolger;
  }
  return sout.str();
}

void Test_Liste::trim(string& info) {                       // trennt Listenname
  size_t doppelpunkt = info.find(": ");
  info.erase(info.begin(), info.begin()+doppelpunkt+2);
}

int read_para(string& parameter){
    string zeile;
    stringstream ss;
    getline(cin, zeile);                                      // Lese ganze Zeile
    int zahl;                                     // erste Zahl wird abgespalten
    ss << zeile;
    ss >> zahl;                                           // zahl gibt Aktion an
    size_t found = zeile.find(" ");                // Alle Zeichen vor Parameter
    if (zeile.length() > 0 && found < zeile.length()) { // loeschen
        zeile.erase(0, found + 1);                        // Deleminter loeschen
    }
    parameter = zeile;                                              // Restzeile
    return zahl;                                                       // Aktion
}


int makeListenwerte(vector<pair<int, int> > &werte, string &para) {
    int bezug(0);
    int eintrag(0);
    char c;
    int anz(0);
    if (para[0] ==' ') para.erase(0,1); // Falls bei Funktionsauswahl Leerzeichen bleibt
    std::istringstream is(para);

    for (std::string cur; getline(is, cur, DELEMITER);) { // zerlegen; Trennzeichen ' '
        std::istringstream isTmp(cur);                   // Teilstring, z.B. 1;3
        isTmp >> bezug >> c >> eintrag;                   // Trennung Teilstring
        if (isTmp.fail() == 1)
            throw wrong_argument();
        // cout << "bezug= " << bezug << "     eintrag= " << eintrag << endl;
        werte.push_back(make_pair(bezug, eintrag));        // Wertekombinationen
        anz++;                                                   // Anzahl Paare
    }
    return anz;                         // Anzahl der Wertepaare "bezug;eintrag"

}

int einlesen_werte(vector<pair<int, int> > &werte, string werteString, string paraString) {
    int anz(0);
    // cout << "Bezug;Eintrag Bezug;Eintrag ..." << endl;
    if (paraString.length()== 0)
        std::getline(std::cin, paraString);       // Eingabezeile komplett lesen
    if (paraString.length()== 0 || paraString.find(TRENNER)== string::npos)
            paraString = werteString;
    anz = makeListenwerte(werte, paraString);

    return anz;                         // Anzahl der Wertepaare "bezug;eintrag"
}

void fuelleListe_vor(Liste &l, string parameter) {
    vector<pair<int, int> > werte;      // Alle Eingabe:  bezug;eintrag als pair
    vector<pair<int, int> >::iterator it;
    try { // bezug;eintrag ...
    einlesen_werte(werte, DEFAULTWERTE_VOR, parameter); // Wenn nicht da, dann Defaultwerte
    for (it = werte.begin(); it != werte.end(); it++) { //Werte in Liste einfuegen
        int bezug = (*it).first;
        int eintrag = (*it).second;
        // Einsetzen in Liste (eintrag NACH bezug)
        l.einfuegen_vor(bezug, eintrag);
    }
     } catch (wrong_argument &e) {
        cout << "Exception: Fehlerhaftes Eingabeformat!" << endl;
    } catch (ListenElementExistiertNicht& element) { // 0;10 10;9 9;8 8;7 4;6 6;5
        cout << "Exception: " << element.wert << " existiert nicht!" << endl;
        // Ausnahme: 4 existiert nicht!
        // cout << l.toString() << endl; // Ausgabe Liste => Listenelement am Ende
    }
}

// =============================================================================
// Tests fuer einfuegen_vor() -> nichts aendern !
// =============================================================================

void Test_Liste::Test_einfuegen_vor_leereListe() {
  tname="Test_einfuegen_vor_leereListe()";
  cout << tname << endl;

  Liste leer1("leer1");
  cout << "Wert (0;1) vorne einfuegen, bei \"bezug\" gleich 0:" << endl;
  leer1.einfuegen_vor(0, 1);                         // eigentliche Pruefschritt
  cout << leer1.toString() << endl;
  string info = leer1.toString(); trim(info);                  // Name abtrennen
  assert( "1 " == info );

  // vorne einfuegen, obwohl "bezug" nicht 0
  Liste leer2("leer2");
  cout << "Wert (2;2) vorne einfuegen, obwohl \"bezug\" nicht 0:" << endl;
  leer2.einfuegen_vor(2, 2);                         // eigentliche Pruefschritt
  cout << leer2.toString() << endl;
  info = leer2.toString(); trim(info);                         // Name abtrennen
  assert( "2 " == info );
  cout << tname << " bestanden" << endl;
}

void Test_Liste::Test_einfuegen_vor_einelementigeListe() {
  tname="Test_einfuegen_vor_einelementigeListe()";
  cout << tname << endl;

   // vor dem Element einfuegen
    cout << "Wert (1;2) vor dem Element einfuegen:" << endl;
Liste eins("eins");
  fuelleListe_vor(eins, "0;1");
  eins.einfuegen_vor(1, 2);                          // eigentliche Pruefschritt
  cout << eins.toString() << endl;
  string info = eins.toString(); trim(info);
  assert( "2 1 " == info);

  // vorne anhaengen
  cout << "Wert (0;2) vorne an Liste anhaengen:" << endl;
  Liste zwei("zwei");
  fuelleListe_vor(zwei, "0;1");
  try {
      zwei.einfuegen_vor(0, 2);                      // eigentliche Pruefschritt
  }
  catch (ListenElementExistiertNicht& element) {
    assert ( 0 == element.wert ); //kein Fehler, Fehler sollte ja geworfen werden
    cout << zwei.toString() << endl;
    info = zwei.toString(); trim(info);
    assert( "2 1 " == info);
    cout << tname << " bestanden" << endl;
    return;
  }
  assert( 0 == 1 );                         // erwartete Ausnahme nicht geworfen
}

void Test_Liste::Test_einfuegen_vor_zweielementigeListe() {
  tname="Test_einfuegen_vor_zweielementigeListe()";
   cout << tname << endl;

   // vor dem ersten Element einfuegen
  cout << "Wert (2;3) vor dem ersten Element einfuegen:" << endl;
  Liste eins("eins");
  fuelleListe_vor(eins, "0;1 1;2");
  eins.einfuegen_vor(2, 3);                          // eigentliche Pruefschritt
  cout << eins.toString() << endl;
  string info = eins.toString(); trim(info);
  assert( "3 2 1 " == info);

  // vor dem zweiten Element einfuegen
  cout << "Wert (1;3) vor dem zweiten Element einfuegen:" << endl;
  Liste zwei("zwei");
  fuelleListe_vor(zwei, "0;1 1;2");
  zwei.einfuegen_vor(1, 3);                          // eigentliche Pruefschritt
  cout << zwei.toString() << endl;
  info = zwei.toString(); trim(info);
  assert( "2 3 1 " == info);

  // vorne anhaengen
  cout << "Wert (0;3) vorne an Liste anhaengen:" << endl;
  Liste drei("drei");
  fuelleListe_vor(drei, "0;1 1;2");
  try {
      drei.einfuegen_vor(0, 3);                      // eigentliche Pruefschritt
  }
  catch (ListenElementExistiertNicht& element) {
    assert ( 0 == element.wert );
    cout << drei.toString() << endl;
    info = drei.toString(); trim(info);
    assert( "3 2 1 " == info);
    cout << tname << " bestanden" << endl;
    return;
  }
  assert( 0 == 1 );                         // erwartete Ausnahme nicht geworfen
}

void Test_Liste::Test_einfuegen_vor_dreielementigeListe() {
  tname="Test_einfuegen_vor_dreielementigeListe()";
  cout << tname << endl;

   // vor dem ersten Element einfuegen
  cout << "Wert (3;4) vor dem ersten Element einfuegen:" << endl;
  Liste eins("eins");
  fuelleListe_vor(eins, "0;1 1;2 2;3");
  eins.einfuegen_vor(3, 4);                          // eigentliche Pruefschritt
  cout << eins.toString() << endl;
  string info = eins.toString(); trim(info);
  assert( "4 3 2 1 " == info);

  // vor dem zweiten Element einfuegen
  Liste zwei("zwei");
  cout << "Wert (2;4) vor dem zweiten Element einfuegen:" << endl;
  fuelleListe_vor(zwei, "0;1 1;2 2;3");
  zwei.einfuegen_vor(2, 4);                          // eigentliche Pruefschritt
  cout << zwei.toString() << endl;
  info = zwei.toString(); trim(info);
  assert( "3 4 2 1 " == info);

  // vor dem dritte Element einfuegen
  cout << "Wert (1;4) vor dem dritten Element einfuegen:" << endl;
  Liste drei("drei");
  fuelleListe_vor(drei, "0;1 1;2 2;3");
  drei.einfuegen_vor(1, 4);                          // eigentliche Pruefschritt
  cout << drei.toString() << endl;
  info = drei.toString(); trim(info);
  assert( "3 2 4 1 " == info);

  // vorne anhaengen
  cout << "Wert (0;4) vorne an Liste anhaengen:" << endl;
  Liste vier("vier");
  fuelleListe_vor(vier, "0;1 1;2 2;3");
  try {
      vier.einfuegen_vor(0, 4);                      // eigentliche Pruefschritt
  }
  catch (ListenElementExistiertNicht& element) {
    assert ( 0 == element.wert );
    cout << vier.toString() << endl;
    info = vier.toString(); trim(info);
    assert( "4 3 2 1 " == info);
    cout << tname << " bestanden" << endl;
    return;
  }
  assert( 0 == 1 );                         // erwartete Ausnahme nicht geworfen
}

// =============================================================================