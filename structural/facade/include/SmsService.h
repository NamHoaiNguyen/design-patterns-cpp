#ifndef sms_service
#define sms_service

template<typename T>
class SmsService {
public:
    SmsService() = default;
    decltype(auto) send_sms(T&& mobilePhone);
};

template<typename T>
decltype(auto) SmsService<T>::send_sms(T&& mobilePhone)
{
    std::cout << "Sending an message to " + mobilePhone << std::endl;
}

#endif