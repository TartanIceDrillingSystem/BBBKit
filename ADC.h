/*
    Copyright 2018 Devin Gund (https://dgund.com)
    https://github.com/dgund/BBBKit/

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef ADC_H_
#define ADC_H_

#include <string>

namespace bbbkit {

class ADC {
public:
    enum PIN { AIN0 = 0,
               AIN1 = 1,
               AIN2 = 2,
               AIN3 = 3,
               AIN4 = 4,
               AIN5 = 5,
               AIN6 = 6
             };

private:
    const std::string nameMap[7] = { "AIN0",
                                     "AIN1",
                                     "AIN2",
                                     "AIN3",
                                     "AIN4",
                                     "AIN5",
                                     "AIN6",
                                   };
    ADC::PIN pin;
    std::string path;
    std::string name;

public:
    ADC(ADC::PIN pin);
    virtual ~ADC();

    // Getters and setters
    
    virtual ADC::PIN getPin() { return pin; }
    virtual std::string getPath() { return path; }
    virtual std::string getName() { return name; }
    
    // Read analog-to-digital value

    // Read raw voltage value (in millivolts)
    virtual int read();
};

} /* namespace bbbkit */

#endif /* ADC_H_ */

