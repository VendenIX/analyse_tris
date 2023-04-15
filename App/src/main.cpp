#include "../include/Model.hpp"
#include "../include/View.hpp"
#include <fstream>
#include <string>
#include <algorithm>

Sorting<int> *selectSort(std::string argv, int *liste, size_t size)
{
    argv = std::string(argv);
    std::transform(argv.begin(), argv.end(), argv.begin(), ::tolower);
    std::cout << argv << std::endl;
    if (argv == "bingosort")
    {
        return new BingoSort<int>(liste, size);
    }
    else if (argv == "bubblesort")
    {
        return new BubbleSort<int>(liste, size);
    }
    else if (argv == "combsort")
    {
        return new CombSort<int>(liste, size);
    }
    else if (argv == "gnomesort")
    {
        return new GnomeSort<int>(liste, size);
    }
    else if (argv == "heapsort")
    {
        return new HeapSort<int>(liste, size);
    }
    else if (argv == "insertionsort")
    {
        return new InsertionSort<int>(liste, size);
    }
    else if (argv == "quicksort")
    {
        return new QuickSort<int>(liste, size);
    }
    else if (argv == "selectionsort")
    {
        return new SelectionSort<int>(liste, size);
    }
    else if (argv == "shellsort")
    {
        return new ShellSort<int>(liste, size);
    } else if (argv == "bucketsort") {
        return new BucketSort<int>(liste, size);
    } else if (argv == "pancakesort") {
        return new PancakeSort<int>(liste, size);
    }
    exit(EXIT_FAILURE);
}

void selectSchuffle(std::string argv, Sorting<int> *s) {
    argv = std::string(argv);
    std::transform(argv.begin(), argv.end(), argv.begin(), ::tolower);
    std::cout << argv << std::endl;
    if (argv == "onetwo") {
        Schuffle<int>::oneTwo(s);
    } else if (argv == "random") {
        Schuffle<int>::random(s);
    } else if (argv == "start25") {
        Schuffle<int>::start25(s);
    } else if (argv == "start50") {
        Schuffle<int>::start50(s);
    } else if (argv == "end50") {
        Schuffle<int>::end50(s);
    } else if (argv == "end25") {
        Schuffle<int>::end25(s);
    } else if (argv == "reverse") {
        Schuffle<int>::reverse(s);
    }
}

int exe(int argc, std::string *argv)
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    if (argc < 3)
    {
        std::cout << "Usage ./Sorting_Algorithm <algo> <size>" << std::endl;
        exit(1);
    }

    writeFileNames(FOLDER);

    std::cout << "----------------------------------------" << std::endl;
    // run_gtk(argc, argv);
    size_t size = std::stoi(argv[2]);

    int liste[size];
    for (size_t i = 0; i < size; i++)
    {
        liste[i] = i;
    }

    Sorting<int> *s = selectSort(argv[1], liste, size); //(Sorting<int>*)&l;

    /*
    Window<int>* w = nullptr;
    if (std::string(argv[3]) != "n") {
        writeFileNames(FOLDER);
        std::vector<std::string> names = readSortNames();
        for (auto name : names) {
            std::cout << name << std::endl;
        }

        Window<int>* w = new Window<int>(1200, 720, s, 60);
        std::cout << "Window = " << w << std::endl;
    }
    */
    // initialize random seed:
    Schuffle<int>::random(s);
    ////std::cout << s->get() << std::endl;
    /*
    if (std::string(argv[3]) != "n") {
        w->schuffled(s);

        while (w->isOpen() && !s->isSorted()) {
            w->pollEvent();
            if (w->isStart()) {
                s->sort();
                std::cout << "Nombre de comparaisons = " << s->getComparisons() << std::endl;
                std::cout << "Nombre de déplacements = " << s->getCount() << std::endl;
                w->update(s->getSwitches());
            } else {
                w->update();
            }
        }
    } else {
        */
    // get time before
    auto start = std::chrono::high_resolution_clock::now();
    s->sort();
    // get time after
    auto end = std::chrono::high_resolution_clock::now();
    // calculate time difference
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds for " << s->getSize() << " elements" << std::endl;
    //}
    ////std::cout << s->get() << std::endl;
    std::cout << "Coût = " << s->getCount() << std::endl;
    std::cout << "Comparaisons = " << s->getComparisons() << std::endl;
    size_t coutRandom = s->getCount();
    size_t comparaisaonRandom = s->getComparisons();
    size_t durationRandom = duration.count();

    /**
     * One Two
     */

    s->resetComparisons();
    s->resetCount();

    Schuffle<int>::oneTwo(s);
    // std::cout << s->get() << std::endl;
    start = std::chrono::high_resolution_clock::now();
    s->sort();
    // get time after
    end = std::chrono::high_resolution_clock::now();
    // calculate time difference
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds for " << s->getSize() << " elements" << std::endl;

    ////std::cout << s->get() << std::endl;
    std::cout << "Coût = " << s->getCount() << std::endl;
    std::cout << "Comparaisons = " << s->getComparisons() << std::endl;
    size_t coutOneTwo = s->getCount();
    size_t comparaisaonOnetwo = s->getComparisons();
    size_t durationOneTwo = duration.count();

    // std::cout << s->get() << std::endl;

    /**
     * Start 25
     */

    s->resetComparisons();
    s->resetCount();

    Schuffle<int>::start25(s);
    // std::cout << s->get() << std::endl;
    start = std::chrono::high_resolution_clock::now();
    s->sort();
    // get time after
    end = std::chrono::high_resolution_clock::now();
    // calculate time difference
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds for " << s->getSize() << " elements" << std::endl;

    ////std::cout << s->get() << std::endl;
    std::cout << "Coût = " << s->getCount() << std::endl;
    std::cout << "Comparaisons = " << s->getComparisons() << std::endl;
    size_t coutStart25 = s->getCount();
    size_t comparaisaonStart25 = s->getComparisons();
    size_t durationStart25 = duration.count();

    // std::cout << s->get() << std::endl;

    /**
     * Start 50
     */

    Schuffle<int>::start50(s);
    // std::cout << s->get() << std::endl;
    start = std::chrono::high_resolution_clock::now();
    s->sort();
    // get time after
    end = std::chrono::high_resolution_clock::now();
    // calculate time difference
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds for " << s->getSize() << " elements" << std::endl;

    ////std::cout << s->get() << std::endl;
    std::cout << "Coût = " << s->getCount() << std::endl;
    std::cout << "Comparaisons = " << s->getComparisons() << std::endl;
    size_t coutStart50 = s->getCount();
    size_t comparaisaonStart50 = s->getComparisons();
    size_t durationStart50 = duration.count();

    // std::cout << s->get() << std::endl;

    /**
     * end 25
     */

    Schuffle<int>::end25(s);
    // std::cout << s->get() << std::endl;
    start = std::chrono::high_resolution_clock::now();
    s->sort();
    // get time after
    end = std::chrono::high_resolution_clock::now();
    // calculate time difference
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds for " << s->getSize() << " elements" << std::endl;

    ////std::cout << s->get() << std::endl;
    std::cout << "Coût = " << s->getCount() << std::endl;
    std::cout << "Comparaisons = " << s->getComparisons() << std::endl;
    size_t coutEnd25 = s->getCount();
    size_t comparaisaonEnd25 = s->getComparisons();
    size_t durationEnd25 = duration.count();

    // std::cout << s->get() << std::endl;

    /**
     * end 50
     */

    Schuffle<int>::end50(s);
    // std::cout << s->get() << std::endl;
    start = std::chrono::high_resolution_clock::now();
    s->sort();
    // get time after
    end = std::chrono::high_resolution_clock::now();
    // calculate time difference
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds for " << s->getSize() << " elements" << std::endl;

    ////std::cout << s->get() << std::endl;
    std::cout << "Coût = " << s->getCount() << std::endl;
    std::cout << "Comparaisons = " << s->getComparisons() << std::endl;
    size_t coutEnd50 = s->getCount();
    size_t comparaisaonEnd50 = s->getComparisons();
    size_t durationEnd50 = duration.count();

    // std::cout << s->get() << std::endl;

    /**
     * Sans mélange
     */

    start = std::chrono::high_resolution_clock::now();
    s->sort();
    // get time after
    end = std::chrono::high_resolution_clock::now();
    // calculate time difference
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds for " << s->getSize() << " elements" << std::endl;

    ////std::cout << s->get() << std::endl;
    std::cout << "Coût = " << s->getCount() << std::endl;
    std::cout << "Comparaisons = " << s->getComparisons() << std::endl;
    size_t coutNo = s->getCount();
    size_t comparaisaonNo = s->getComparisons();
    size_t durationNo = duration.count();

    /**
     * reverse
     */

    s->resetComparisons();
    s->resetCount();

    Schuffle<int>::reverse(s);
    // std::cout << s->get() << std::endl;
    start = std::chrono::high_resolution_clock::now();
    s->sort();
    // get time after
    end = std::chrono::high_resolution_clock::now();
    // calculate time difference
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds for " << s->getSize() << " elements" << std::endl;

    ////std::cout << s->get() << std::endl;
    std::cout << "Coût = " << s->getCount() << std::endl;
    std::cout << "Comparaisons = " << s->getComparisons() << std::endl;
    size_t coutreverse = s->getCount();
    size_t comparaisaonreverse = s->getComparisons();
    size_t durationreverse = duration.count();

    /**
     * Ecriture dans fichier
     */

    std::string filename = argv[1] + ".csv";
    std::string contenu = std::to_string(size);
    contenu += ",";
    contenu += std::to_string(coutRandom);
    contenu += ",";
    contenu += std::to_string(comparaisaonRandom);
    contenu += ",";
    contenu += std::to_string(durationRandom);

    contenu += ",";
    contenu += std::to_string(coutOneTwo);
    contenu += ",";
    contenu += std::to_string(comparaisaonOnetwo);
    contenu += ",";
    contenu += std::to_string(durationOneTwo);

    contenu += ",";
    contenu += std::to_string(coutStart25);
    contenu += ",";
    contenu += std::to_string(comparaisaonStart25);
    contenu += ",";
    contenu += std::to_string(durationStart25);

    contenu += ",";
    contenu += std::to_string(coutStart50);
    contenu += ",";
    contenu += std::to_string(comparaisaonStart50);
    contenu += ",";
    contenu += std::to_string(durationStart50);

    contenu += ",";
    contenu += std::to_string(coutEnd25);
    contenu += ",";
    contenu += std::to_string(comparaisaonEnd25);
    contenu += ",";
    contenu += std::to_string(durationEnd25);

    contenu += ",";
    contenu += std::to_string(coutEnd50);
    contenu += ",";
    contenu += std::to_string(comparaisaonEnd50);
    contenu += ",";
    contenu += std::to_string(durationEnd50);

    contenu += ",";
    contenu += std::to_string(coutNo);
    contenu += ",";
    contenu += std::to_string(comparaisaonNo);
    contenu += ",";
    contenu += std::to_string(durationNo);

    contenu += ",";
    contenu += std::to_string(coutreverse);
    contenu += ",";
    contenu += std::to_string(comparaisaonreverse);
    contenu += ",";
    contenu += std::to_string(durationreverse);

    contenu += "\n";
    std::cout << "File = " << filename << "\nContenu = " << contenu;

    std::ofstream file;
    file.open(filename.c_str(), std::ios::app);
    file << contenu.c_str();
    file.close();

    s->~Sorting();

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    // Visu
    if (argc < 3) {
        std::cout << "Usage ./Sorting_Algorithm <algo tri> <algo mélange>" << std::endl;
        std::cout << "Algo tri :\n\tbingosort\n\tbubblesort\n\tcombsort\n\tgnomesort\n\theapsort\n\tinsertionsort\n\tquicksort\n\tselectionsort\n\tshellsort"<< std::endl;
        std::cout << "Algo mélange :\n\trandom\n\toneTwo\n\tstart25\n\tstart50\n\tend25\n\tend50" << std::endl;
        exit(1);
    }

    size_t size = 100;

    int liste[size];
    for (size_t i = 0; i < size; i++) {
        liste[i] = i;
    }

    Sorting<int> *s = selectSort(std::string(argv[1]), liste, size); //(Sorting<int>*)&l;

    Window<int>* w = new Window<int>(1200, 720, s, 60);
    std::cout << "Window = " << w << std::endl;

    selectSchuffle(std::string(argv[2]), s);

    w->schuffled(s);

    while (w->isOpen() && !s->isSorted()) {
        w->pollEvent();
        if (w->isStart()) {
            s->sort();
            std::cout << "Nombre de comparaisons = " << s->getComparisons() << std::endl;
            std::cout << "Nombre de déplacements = " << s->getCount() << std::endl;
            w->update(s->getSwitches());
        } else {
            w->update();
        }

    }

    w->~Window();
    s->~Sorting();

    // run_gtk(argc, argv);

    /* // CSV

    if (argc < 2) {
        std::cout << "Usage ./Sorting_Algorithm <algo tri>" << std::endl;
        std::cout << "Algo tri :\n\tbingosort\n\tbubblesort\n\tcombsort\n\tgnomesort\n\theapsort\n\tinsertionsort\n\tquicksort\n\tselectionsort\n\tshellsort"<< std::endl;
        exit(1);
    }

    std::string name = std::string(argv[1]);
    std::string filename = name + ".csv";
    std::ofstream file;
    file.open(filename.c_str());
    file << "";
    file.close();
    std::cout << "Hello, World!" << std::endl;

    for (int i = 1; i <= 10000; i++) {
        std::cout << "Itération num = " << i << std::endl;
        std::string call[3] = {std::string(argv[0]), std::string(argv[1]), std::to_string(i)};
        exe(3, call);
    }
    */

    return EXIT_SUCCESS;
}