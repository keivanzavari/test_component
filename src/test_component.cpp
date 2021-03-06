#include "test_component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

TestComponent::TestComponent(std::string const& name) : TaskContext(name)
{
    // Properties
    this->addProperty("prop",     prop_).doc("property");


    // Ports
    this->addPort("double_outport", double_outport_).doc("double values");

    // operations
    this->addOperation("setValue", &TestComponent::setValue, this, RTT::OwnThread)
        .doc("Set the desired value");

    std::cout << "TestComponent constructed !" <<std::endl;
}

bool TestComponent::configureHook() {

    std::cout << "TestComponent configured !" <<std::endl;
    return true;
}

bool TestComponent::startHook() {
    double_outport_.write(0);

    std::cout << "TestComponent started !" <<std::endl;
    return true;
}

void TestComponent::updateHook() {
    std::cout << "TestComponent executes updateHook !" <<std::endl;
}

void TestComponent::stopHook() {
    std::cout << "TestComponent executes stopping !" <<std::endl;
}

void TestComponent::cleanupHook() {
    std::cout << "TestComponent cleaning up !" <<std::endl;
}

bool TestComponent::setValue(double value)
{
    prop_ = value;
}
/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(TestComponent)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(TestComponent)
