#include "LogisticsFactory.hpp"

LogisticsFactory::~LogisticsFactory()
{}

Transport* LogisticsFactory::planDelivery()
{
    return this->createTransport();
}