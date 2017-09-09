#include <functional>
#include <sstream>
#include <string>

// symmetric difference quotient
double differentiate(std::function<double(double)> f, double h, double x)
{
    return (f(x + h) - f(x - h)) / (2 * h);
}

std::string estimated_velocity(std::function<double(double)> distance, double time, double precision)
{
    auto velocity = differentiate(distance, precision, time);

    std::stringstream output;
    output << "Estimated velocity after " << time << " seconds is " << velocity << " m/s.";

    return output.str();
}

