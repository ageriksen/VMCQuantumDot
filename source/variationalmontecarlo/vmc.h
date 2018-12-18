#ifndef VMC_H
#define VMC_H

#include <vector>
#include <string>

class VMC
{
    public:
        VMC( int Particles, int Dimensions, int Processors, int Rank ):
            m_Processors(Processors), m_Rank(Rank),
            m_Particles(Particles), m_Dimensions(Dimensions)
        {
            std::vector<double> dimensions(m_Dimensions, 0.0);
            m_oldPositions.resize(m_Particles, dimensions);
            m_newPositions.resize(m_Particles, dimensions);
        }

        void integrate( int NCycles, double stepLength);

        virtual double stepFinder( std::vector<double> variables ) = 0;
        virtual std::vector<double> optimize
        (
             std::vector< std::vector<double> > Parameters,
             unsigned index,
             std::vector<unsigned> range
        );

        virtual std::vector<double> firstMinimum
        (
            std::vector< std::vector<double> > Parameters,
            std::string baseName
        ) = 0;

        virtual std::vector<double> minimum( std::vector<double> variables );

        virtual void clean() = 0;

        //getters and setters:

    protected:
        // MC
        int m_NCycles;
        double m_stepLength;
        double m_oldPowers;
        double m_newPowers;
        std::vector< std::vector<double> > m_oldPositions;
        std::vector< std::vector<double> > m_newPositions;
        // parallelization
        int m_Processors;
        int m_Rank;
        // system
        int m_Particles;
        int m_Dimensions;
        //int vector< vector<double> > m_Parameters;
        //Wavefunction *pm_WF = nullptr;
        // Observables
        double m_kinetic;
        double m_potential;
        double m_energy;
        double m_energySquared;
        double m_variance;

};

#endif //VMC_H
