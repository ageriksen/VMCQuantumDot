#ifndef RANDOM_H
#define RANDOM_H

#include <random>
//std::mt19937_64 m_engine(m_device);
//std::uniform_real_distribution<type> m_typeUniformDistribution(min, max);

class Random
{
    public:
        Random( int rank )
        {
            m_engine = std::mt19937_64( m_device() + rank );
        }

        void uniformReal( double min, double max )
        {
            m_uniformReal = std::uniform_real_distribution<double>(min, max);
        }

        // getters
        double RNG() { return m_uniformReal( m_engine ); }

    private:
        std::random_device m_device;
        std::mt19937_64 m_engine;
        std::uniform_real_distribution<double> m_uniformReal;

};

#endif // RANDOM_H
