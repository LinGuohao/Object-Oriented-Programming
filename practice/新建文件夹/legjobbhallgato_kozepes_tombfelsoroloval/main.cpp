/*
Feladat: Az inputfájl középiskolai tanulók eredményeit tartalmazza. A fájl minden sora egy hallgató nevével
(szóköz nélküli sztring) kezdődik, amelyet egy tárgy neve (szintén szóköz nélküli sztring) majd a tanuló adott tárgyból
szerzett eredményei követnek. Egy eredmény egy tevékenységből (szóköz nélküli sztring) és egy osztályzatból áll.
Példa az input fájl soraira:

Feri irodalom dolgozat 4 felelet 1 essze 2 kiseloadas 4
Feri matematika dolgozat 2 felelet 4 szorgalmi 5

Adjuk meg azt a tanulót, akinek valamelyik tárgyból a legjobb az átlaga az összes tárgyat és tanulót figyelembe véve.
A tárgyat is adjuk meg, ahol a hallgató a legjobb átlagot elérte.
*/

/*
A megoldás során nem használhatunk a fájl méretétől függő változót (értsd: nem tehetjük bele a fájl sorait egy a fájl
sorainak számával megegyező hosszú tömbbe. A fájl egy-egy sorának feldolgozásához használunk tömböt, hogy ugyanazokat az elemeket
többször bejárhassuk, elkerülve több tétel összevonását egy közös ciklus köré szervezését.)
*/
#include <iostream>
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/arrayenumerator.hpp"
#include "../library/counting.hpp"

using namespace std;

// Az inputfájl egy sorában a név és tárgy után ilyen Mark típusú elemek (a feladatszöveg Eredménynek nevezi) vannak.
struct Mark
{
    string task;
    int grade;
    // Hallgatónként illetve tárgyanként változhat, az inputfájl melyik sorában hány Mark típusú rekord van.
    // Ciklussal tudjuk őket bejárni, de egy tétel alkalmazhatóságához a felsorolt elemek típusa ugyanolyan kell legyen, ezért az
    // összetett (egy sztring és egy egész alkotta) Mark típusú struktúra beolvasó operátorának megírása itt kötelező
    friend istream &operator>>(istream& is,Mark &m)
    {
        is >> m.task >> m.grade;
        return is;
    }
};

// Egy sorban lévő Mark típusú elemeket beolvassuk és elhelyezzük őket egy vector-ban. Tesszük ezt azért, mert a vector-t többször
// bejárhatjuk, ellentétben pl. egy stringstream által szolgáltatott elemekkel.
// Természetesen saját ciklust nem írunk, hanem az összegzés sablonosztály azon változatát használjuk ahol a
// (kiszámolt) függvényérték vector típusú.
class FillVector : public Summation<Mark, vector<Mark> >
{
    Mark func(const Mark &e) const override { return e; }
};

// Jegyek darabszámát határozzuk meg. Minden jegyet meg akarunk számolni, így a cond feltétel az azonosan IGAZ függvény,
// ami minden elemre igaz. Mivel ez az alapértelmezés, felüldefiniálása elhagyható.
// Mark típusú elemeket járunk be. Ezt a tételt majd egy tömb felsorolójával kapcsoljuk össze, a tételt leíró osztály
// egy objektumának addEnumerator() metódusának meghívásával.
class CountOfGrades : public Counting<Mark>
{
    bool cond(const Mark& e) const override final { return true;};
};

// Jegyek összegét határozzuk meg, hogy a darabszám és összeg ismeretében átlagot számolhassunk.
// Mark típusú elemeket járunk be. Az összegzés f függvénye egy felsorolt Mark típusú elemhez annak jegy (grade) részét
// rendeli, ami egy egész szám.
// Tehát a bejárt eleme képei egész típusúak, két ilyen függvényérték a+b összege is egész, ezt írja le az add() metódus.
class SumOfGrades : public Summation<Mark,int>
{
    int func(const Mark& e) const override { return e.grade; }
    int neutral() const override { return 0; }
    int add( const int& a, const int& b) const override { return a+b; }
};

// A feladat megoldásához soroljunk fel Student típusú elemeket, megadva minden hallgatóról az adott tárgyból elért
// átlagát. Az inputfájlban nem ilyen típusú elemek vannak; az inputfájl minden sora tartalmazza egy hallgató és egy
// tárgy nevét, majd tevékenység-jegy párokat. Utóbbiakból kiszámítható a hallgató adott tárgyból elért átlaga.
// Azaz, pont ugyanannyi elemet sorolunk fel mint ahány sora az inputfájlnak volt, azzal a különbséggel hogy a
// tevékenység-jegy párok sorozatát egyetelen átlaggá "konvertáljuk"; tehát már beolvasáskor meghatározzuk egy
// hallgató-tárgy párhoz a hallgató adott tárgyból elért átlagát.
struct Student
{
    public:
    string name;
    string course;
    double avg;
    // Később majd Student típusú elemeket sorulunk fel. Nem az inputfájl sorait, hanem minden sorból csak a fontos
    // információt megtartva: hallgató neve, tárgy neve, a hallgató átlaga az adott tárgyból.
    // Ezért egy Student típusú elem beolvasása az inputfájl egy sorának "konvertálását" jelenti;
    // megtartjuk a hallgató és a tárgy nevét, az eredmény párokból átlagot számolunk.
    friend istream &operator>>(istream& is,Student &st)
    {
        string line;
        getline(is,line);
        stringstream ss(line);
        ss >> st.name;
        ss >> st.course;

        // Az ss már csak a Mark típusú tevékenység-jegy párokat tartalmazza. Ezeket felsorolva kiszámoljuk az átlagot.
        // A könnyebb feldologozhatóság miatt az ss elemeit belepakoljuk egy vector-ba.
        vector<Mark> x;
        FillVector pr;
        StringStreamEnumerator<Mark> enor(ss);
        pr.addEnumerator(&enor);
        pr.run();
        x = pr.result();

        // Kiszámoljuk a jegyek összegét, most már a tömbfelsorolót használva.
        ArrayEnumerator<Mark> arrayenor(&x);
        SumOfGrades sog;
        sog.addEnumerator(&arrayenor);
        sog.run();
        int s = sog.result();

        // Kiszámoljuk a jegyek számát, most már a tömbfelsorolót használva.
        // Valójában ehhez nem kéne programozási tétel, ciklus; a jegyek száma megegyezik az x vector hosszával.
        CountOfGrades cog;
        cog.addEnumerator(&arrayenor);
        cog.run();
        int c = cog.result();

        if (c == 0)
        {
            st.avg = 0;
        }
        else
        {
            st.avg = double(s) / c; // int/int=int típusú lenne
        }
        return is;
    }
};

// Amennyiben hallgatónként és tárgyaknént fel tudjuk sorolni az elért átlagot, a kitűzött feladatot megoldhatjuk
// egy maximumkiválasztással.
// Természetesen a függvény - aminek a maximumát keressük - nem más, mint ami egy felsorolt elemhez
// annak átlag részét rendeli.
class BestStudent : public MaxSearch<Student,double>
{
    double func(const Student& e) const override
    {
        return e.avg;
    }
};

int main()
{

    // a seqInFileEnumerator-nak van exception-je, ezért a try..catch használata kötelező
    try
    {
        SeqInFileEnumerator<Student> enor("input.txt");

        BestStudent bs;
        bs.addEnumerator(&enor);
        bs.run();
        // Sima (nem feltételes) maximumkiválasztás esetén a cond feltétel alapértelmezés szerint azonosan igaz;
        // minden felsorolt elem között keressük a maximumot.
        // Maximumkiválasztásnál is használható a found(), annak eldöntésére hogy üres volt-e a felsoroló.
        if (bs.found())
        {
            // max érték - opt(), a mi esetünkben ez egy átlag
            // maxot felvevő elem - optElem(), a mi esetünkben ez Student típusú
            cout << "Best student: "<< bs.optElem().name << ", Course: " << bs.optElem().course
                 << " Average: "<< bs.opt() << endl;
        }
    }
    catch (SeqInFileEnumerator<Student>::Exceptions err)
    {
        cout<<"File not found.";
    }
    return 0;
}
