#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "graph.h"
#include "Airport.h"

queue<Airport> getAirports(string file){
    cout<<"Reading Airports file...\n";
    ifstream fout;
    file="../"+file;
    fout.open(file);
    string tempstream,airportCode,airportName,airportCity,airportCountry,airportLatitude,airportLongitude;
    getline (fout, tempstream);
    queue<Airport> airports;
    while (getline (fout, tempstream)) {
        stringstream it_stream(tempstream);
        getline(it_stream,airportCode,',');
        getline(it_stream,airportName,',');
        getline(it_stream,airportCity,',');
        getline(it_stream,airportCountry,',');
        getline(it_stream,airportLatitude,',');
        getline(it_stream,airportLongitude,'\r');

        double latitude = stod(airportLatitude);
        double longitude = stod(airportLongitude);
        Airport airport = Airport(airportCode,airportName,airportCity,airportCountry,latitude,longitude);
        airports.push(airport);
    }
    cout << "Finished reading.\n";
    fout.close();
    return airports;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    queue<Airport> airports = getAirports("dataset/airports.csv");
    int sizeGraph = airports.size();
    Graph airportGraph = Graph(sizeGraph);
    airportGraph.addAirports(airports);
    airportGraph.getAirlines("dataset/airlines.csv");
    airportGraph.getFlights("dataset/flights.csv");
    //airportGraph.getShortestPath("CDG","LGA");
    airportGraph.getAvailableFlights("CDG");
    //airportGraph.getDestinations("CDG");
    cout << "Got here";
    return 0;
}


/*
 * FAZER A CENA DOS PAISES E CIDADES
 * MENU
 *
 * EXTRA:
 * De quantos países diferentes?
 * Quantos aeroportos, cidades ou países são atingíveis usando um máximo de Y voos?
 *
 *
 */