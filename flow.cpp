
int main()
{
  auto src = framework.get_src();
  auto tcp_receiver = framework.get_src();

  // TCP TX
  src >> json_builder >> http_builder >> tcp_sender; 
  tcp_receiver["port80"] >> http_parser["Contents-Type:application/json"] >> json_view;
                            http_parser["Contents-Type:plain/text"] >> [] (const std::string& txt) { cout << txt; };

  // TCP RX
  tcp_receiver["port22"] >> ftp_parser >> file_writer["~/received_file"];

  return 0;
}
