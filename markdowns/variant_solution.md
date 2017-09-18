# std::variant

## Possible solution

```C++
#include <functional>
#include <sstream>
#include <string>
#include <variant>

// symmetric difference quotient
std::variant<double, std::string> differentiate(std::function<double(double)> f, double h, double x)
{
    if((std::isnan(h)) || (h <= 0)) { return "invalid precision"; }
    if((std::isnan(x)) || (x < 0)) { return "invalid time"; }

    auto const d = f(x + h) - f(x - h);
    if(std::isnan(d)) { return "bad motion function"; }

    return d / (2 * h);
}

std::string estimated_velocity(std::function<double(double)> distance, double time, double precision)
{
    auto velocity = differentiate(distance, precision, time);

    std::stringstream output;

    if(std::holds_alternative<double>(velocity)) {
        output << "Estimated velocity after " << time << " seconds is " << std::get<double>(velocity) << " m/s.";
    } else {
        output << "Estimation failed because of " << std::get<std::string>(velocity) << ".";
    }

    return output.str();
}
```
