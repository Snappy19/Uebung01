#include "json.hpp"

#include "Candidate.h"
#include "miRNA.h"
#include "alignment.h"
#include "GenomeProcessor.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <regex>


using namespace std;
using json = nlohmann::json;


/*
json readParameters(const char* path)
{
    std::ifstream istrm(path);

    if(!istrm) {
        std::cerr << "Could not open file " << path << " for reading.\n";

        // Call exit here to avoid complicated error handling. Only use this
        // method in the main file as it makes program abortion unrecoverable
        // and hard to predict.
        std::exit(-2);
    }

    try {
        json parameters;
        istrm >> parameters;

        return parameters;
    } catch(const std::invalid_argument& e) {
        std::cerr << "Error while parsing config file: " << e.what() << '\n';
    }

    // See above
    std::exit(-3);
}
*/

int main(int argc, char* argv[]) {

    /*  Funktion zum schreiben in eine datei
    fstream f;
    f.open("test.dat", ios::out);
    f << "Dieser Text geht in die Datei" << endl;
    f.close();
    */

    /**
     * TODO: Eingabe sensitiv auf Mensch und alles andere machen: 2 Programme, entweder Mensch oder anderer Organismus
     * Mensch zb:   if (substr == >NC) dann nächste zeile GO    else DO NOT                evtl noch chromosme ID abfangen um das in der gff3 nachzuschauen
     * Bei anderen: if (substr == >) dann nächste Zeile GO     else (gibst glaub ned)      auch hier ID abfangen (kann 1-19 oder X,Y,M sein)
     *
     * TODO: miRNA richtig einlesen und konvertieren --- KLAPPT!!!
     *
     * TODO: über align Algorithmus Gedanken machen
     *
     * TODO: Chromosom Klasse erstellen
     *  --- aufgehört bei --align mouse
     *          miRNA ready gemacht, jetzt gehts drum Genom zu verarbeiten --> deswegen Chromosom Klasse? Mit ID und Sequence Feldern?
     */
/*
    string line;
    string mirna_line;
    fstream file;
    fstream mirna_file;
    ofstream genome_doc;
    //vector<size_t> vec;
    map<size_t, Candidate> map;

    mirna_file.open(argv[2]);

    string mirna_from_file;
    string mirna_id;

    if(!mirna_file.is_open())
        return -1;

    while (getline(mirna_file, mirna_line)) {

        if (mirna_line.substr(0, 1) == ">") {

            mirna_id = mirna_line.substr(1, mirna_line.find(' '));

        }      // hier noch ID also Chromosomenzahl rauskriegen (wichtig später gff3 nachschauen)
        else {
            mirna_from_file.append(mirna_line);
        }
    }

    cout << "Test ob miran eingelesen wurde: \n" << mirna_from_file << endl;
    cout << "Test ob mirna ID eingelesen wurde: \n" << mirna_id << endl;

    //string miRNA = "CAGCUCUAGUAGAUUCUA";    // 18 chars

    converter conver(mirna_from_file);                // miRNA converter/translator
    conver.complementary_RNA();
    conver.convert_to_DNA();


    string token =  conver.getSeq().substr(1,4);      // 4 chars "TACG"   //TODO das später so machen, dass du die beiden Zahlen als variabalen weitergibst und dann unten entsprechend start damit berechnest
    size_t miRNA_size = mirna_from_file.size();                 // 18
    //bool flag = false;

    cout << "Test miRNA 4 chars langer Substring: " << token
         << "\nCheck to see if miRNA size is correct (18): " << miRNA_size << endl;

    size_t current_line = 1;
    size_t id = 1;
    size_t start, end;
    size_t count = 0;
    string chr_id;                      // maybe set it to size_t and use stoi() function later to get id as int
    //size_t testlen;

    string genome;
    string genome_line;
    bool first_found = true;

    file.open(argv[1]);     /// meine chromosom_1 Test Fasta Datei
    genome_doc.open(R"(C:\\Users\\Snappy\\Documents\\Bachelor\\Genome\\Beispiele\\test.fa)");

    if(!file.is_open())
        return -1;

    while (getline(file,genome_line)){
        if(genome_line.substr(0,1) == ">"){
            if(first_found){
                genome.append(genome_line);
                genome.append("\n");
                first_found = false;
            } else {
                genome.append("\n");
                genome.append(genome_line);
                genome.append("\n");
            }
        }
        else {
            genome.append(genome_line);
            //genome_doc << genome_line;
        }
        genome_doc << genome;
    }

    // genome_doc << genome << endl;

    fstream genome_doc_open;
    genome_doc_open.open(R"(C:\\Users\\Snappy\\Documents\\Bachelor\\Genome\\Beispiele\\test.fa)");
    string dna_seq;

    while (getline(genome_doc_open, line)) {

        if (line.substr(0, 1) == ">") {
            chr_id.clear();
            chr_id.append(line.substr(1, line.find(' ')));      // maybe use stoi() function so that chr_id is int instead of a string
            count = 0;
        }
        else {

            size_t pos = line.find(token);
            while (pos != std::string::npos) {
                start = pos + (count*60);                       // pos statt pos-1, da es 0. position nicht gibt -> pos fängt aber bei 0 an, daher kein -1
                end = pos + miRNA_size + (count*60);

                // extract DNA sequenz in length of miRNA
                dna_seq = line.substr(start-1, miRNA_size);

                Candidate can(start, end, dna_seq, chr_id);               // will statt token die DNA sequenz um diesen Treffer herum betrachten ---> selbes Problem wie oben: Wie komm ich da ran???
                map.insert(pair<size_t, Candidate>(id, can));
                pos = line.find(token, pos + token.size());
                id++;
                dna_seq.erase();
            }
            current_line++;
            count++;
        }
    }


    ofstream results;
    results.open(R"(C:\\Users\\Snappy\\Documents\\Bachelor\\Genome\\Beispiele\\results.fa)");

    std::cout << "results have been wirtten into 'results'\n";
    //map.erase(2);
    for (auto it : map){
        results << "Candidate ID:" << it.first << " Chr.: " << it.second.getChrID(it.second) <<" => "
                << it.second.getStart(it.second) << " - " << it.second.getEnd(it.second)
                << "  sequence: " << it.second.getSeq(it.second) <<'\n';
    }

    for(auto it = map.begin(); it != map.end(); ++it){
        results << "Candidate ID:" << it->first << " Chr.: " << it->second.getChrID(it->second) <<" => "
             << it->second.getStart(it->second) << " - " << it->second.getEnd(it->second)
             << "  sequence: " << it->second.getSeq(it->second) <<'\n';
    }

    //return 0;

*/
    /// Ab hier der richtige code mit command line arguments and stuff

/*
    printf("arguments: %d\n", argc);
    for(int i = 0; i < argc; i++) {
        printf("argument %d: %s\n", i, argv[i]);
    }
*/
    /**
     * Würde gern mit getopt arbeiten
     * -align_organism bleibt erstmal (darüber mach ich mir dann noch
     *
     */


    if (argc < 2){
        cerr << "Not enough arguments!\nUsage:\n\t"
                  << "--align_organism miRNA.fa genome.fa config.json\nor\n\t"           // später wieder out_prefix dazumachen
                  << "--align_organism miRNA.fa chromosome.fa config.json\nor\n\t"       // werd ich vermutlich wegmachen, nur zu Testgründen erstmal da
                  << "--test miRNA.fa\n";
        return -1;
    }

    string option = argv[1];

    if (option == "--test"){
        if (argc == 3){

            cout << "Running test miRNA\n";

            // Ich komm hierauf nochmal zurück, aber zuerst passiert nichts
            miRNA mirna(argv[2]);

            cout << "miRNA ID: " << mirna.get_miRNAId() << endl;

            mirna.generate_complementary_RNA();

            cout << "original string -- complementary string: \n"
                 << mirna.get_miRNASequence() << endl << mirna.get_changed_miRNASequence() << endl;

            mirna.convert_to_DNA();

            cout << "The finished processed miRNA: \n" << mirna.get_changed_miRNASequence() << endl;

            mirna.set_miRNAToken(4);

            cout << "The Token. This will be the 'word' that we try to find in DNA Sequence:\n"
                 << mirna.getToken() << endl;

            return 0;

        } else {
            cerr << "Too many arguments used with command --test!\nUsage:\n\t"
                 << "--align_organism miRNA.fa genome.fa config.json\n\t"
                 << "--align_organism miRNA.fa chromosome.fa config.json\n\t"
                 << "--test miRNA.fa\n";
            return -1;
        }
    }
    else if (option == "--align_mouse"){
            if (argc == 5){
                cout << "Running align miRNA with DNA\n";

                auto parameters = readParameters(argv[4]);
                size_t token_size = parameters["token_size"];
                //size_t overlap = parameters["overlap"];             // overlap, wird zu mirna-Länge dazu addiert, um zb statt 18 -> 25 lange nt sequenzen aus DNA zu speichern
                                                                    // wird gemacht, weil ja auch Lücken im alignment sein können

                // arg[2] = miRNA || argv[3] = genome || argv[4] = json
                miRNA mirna_mouse(argv[2]);                 // construct miRNA object
                mirna_mouse.generate_complementary_RNA();   // generate complementary string to miRNA sequence
                mirna_mouse.convert_to_DNA();               // convert the new sequence into a DNA sequence
                mirna_mouse.set_miRNAToken(token_size);     // set token = word, that we will search for in genome

                cout << "miRNA input ID + sequence: \n" << mirna_mouse.get_miRNAId() << "   " << mirna_mouse.get_miRNASequence() << endl;
                cout << mirna_mouse.get_changed_miRNASequence() << endl;
                cout << "Token: " << mirna_mouse.getToken() << endl;

                GenomeProcessor genpro(argv[3]);
                genpro.other_organism();

                cout << "Organism: " << genpro.getOrganism() << endl;

                ofstream results;
                results.open(R"(C:\\Users\\Snappy\\Documents\\Bachelor\\Genome\\Beispiele\\results.fa)");

                for (auto it : genpro.getProcessedGenome()){
                    results << "Map Item NR.:" << to_string(it.first) << "  Chr. ID: " << it.second.getChromosomeID()
                            << "\nSequence: " << it.second.getChromosomeSeq() << endl;
                }

                //TODO: Here happens the magic --- mouse align

                return 0;
            } else {

                cerr << "Too many or too few arguments used with command --align!\nUsage:\n\t"
                    << "--align_organism miRNA.fa genome.fa config.json\n\t"
                    << "--align_organism miRNA.fa chromosome.fa config.json\n\t"
                    << "--test miRNA.fa\n";
                return -1;
            }
    } else  if(option == "--align_human"){
        if(argc == 5) {
            cout << "Running align miRNA with DNA (genome or chromosome)\n";

            //TODO: Here happens the magic --- human align

            return 0;
        } else {

            cerr << "Too many or too few arguments used with command --align!\nUsage:\n\t"
                 << "--align_organism miRNA.fa genome.fa config.json\n\t"
                 << "--align_organism miRNA.fa chromosome.fa config.json\n\t"
                 << "--test miRNA.fa\n";
            return -1;
        }
    } else {
        cerr << "wrong/unknown command!\nUsage:\n\t"
                << "--align_organism miRNA.fa genome.fa config.json\n\t"
                << "--align_organism miRNA.fa chromosome.fa config.json\n\t"
                << "--test miRNA.fa\n";
        return -1;
    }

 }

