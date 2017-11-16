#ifndef OROCOS_TEST_COMPONENT_COMPONENT_HPP
#define OROCOS_TEST_COMPONENT_COMPONENT_HPP

#include <rtt/RTT.hpp>

class TestComponent : public RTT::TaskContext{
    public:
        TestComponent(std::string const& name);
        bool configureHook();
        bool startHook();
        void updateHook();
        void stopHook();
        void cleanupHook();

        bool setValue(double);
    private:
        RTT::OutputPort< double >      double_outport_;

        double prop_;

};
#endif
