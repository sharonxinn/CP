// Annihilation rules: 
// A on left of B: Annihilate (A must be on the left of B)
// B and B: Annihilate
// Find min number of particles that remain
// AABB = 0 
// AA = 2
// BBA = 1 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;

    vector<string> particles;
    vector<int> remainingParticles;

    for (int i = 0; i < num; i++) {
        string p;
        cin >> p;
        particles.push_back(p);
    }

    for (int i = 0; i < particles.size(); i++) {
        vector<char> aliveParticles;
        string currentP = particles[i];

        for (int j = 0; j < currentP.length(); j++) {
            char currentLetter = currentP[j];

            if (currentLetter == 'A') {
                aliveParticles.push_back('A');
            }

            else if (currentLetter == 'B') {
                if (!aliveParticles.empty() && aliveParticles.back() == 'A') {
                    // AB
                    aliveParticles.pop_back();
                }
                else if (!aliveParticles.empty() && aliveParticles.back() == 'B') {
                    // BB
                    aliveParticles.pop_back();
                }
                else {
                    // BA no annihilate
                    aliveParticles.push_back('B');
                }
            }
        }
        remainingParticles.push_back(aliveParticles.size());
    }

    for (int i = 0; i < remainingParticles.size(); i++) {
        cout << remainingParticles[i] << endl;
    }

    return 0;
}