udacity-payment-app
===================

This repository contains a project submitted for the **Udacity Embedded Systems Professional** nanodegree.

Testing the Application
-----------------------

The application requires `Platform Toolset v143` which is supplied with `Visual Studio 2022`. The application uses Microsoft VC++ specific extensions which isn't portable to other platforms or compilers.

Rubric's Required Screenshots and Videos
----------------------------------------

This section contains list of the images and videos requested by the project's rubric to be attached to the application.

- Development environment preparation
  - [Solution Explorer](docs/1_development_environment/1_folder_structure.png)
  - [app.h](docs/1_development_environment/2_1_app_h.png)
  - [card.h](docs/1_development_environment/2_2_card_h.png)
  - [terminal.h](docs/1_development_environment/2_3_terminal_h.png)
  - [server.h](docs/1_development_environment/2_4_server_h.png)
- Implement the card module
  - [getCardHolderNameTest](docs/2_card_module/1_getCardHolderNameTest.png)
  - [getCardExpiryDateTest](docs/2_card_module/2_getCardExpiryDateTest.png)
  - [getCardPANTest](docs/2_card_module/3_getCardPANTest.png)
  - 🎥 [Card Module Video](docs/2_card_module/vid_card_module.mp4)
- Implement the terminal module
  - [getTransactionDateTest](docs/3_terminal_module/1_getTransactionDateTest.png)
  - [isCardExpriedTest](docs/3_terminal_module/2_isCardExpriedTest.png)
  - [getTransactionAmountTest](docs/3_terminal_module/3_getTransactionAmountTest.png)
  - [isBelowMaxAmountTest](docs/3_terminal_module/4_isBelowMaxAmountTest.png)
  - [setMaxAmountTest](docs/3_terminal_module/5_setMaxAmountTest.png)
  - 🎥[Terminal Module Video](docs/3_terminal_module/vid_terminal_module.mp4)
- Implement the server module
  - [accountsDB](docs/4_server_module/1_accountsDB.png)
  - [transactionsDB](docs/4_server_module/2_transactionsDB.png)
  - [recieveTransactionDataTest](docs/4_server_module/3_recieveTransactionDataTest.png)
  - [isValidAccountTest](docs/4_server_module/4_isValidAccountTest.png)
  - [isBlockedAccountTest](docs/4_server_module/5_isBlockedAccountTest.png)
  - [isAmountAvailableTest](docs/4_server_module/6_isAmountAvailableTest.png)
  - [saveTransactionTest](docs/4_server_module/7_saveTransactionTest.png)
  - [listSavedTransactionsTest](docs/4_server_module/8_listSavedTransactionsTest.png)
  - 🎥 [Server Module Video](docs/4_server_module/vid_server_module.mp4)
- Implement the application
  - 🎥 [Application Video](docs/5_app/vid_app.mp4)
- Testing the application
  - [Transaction approved user story](docs/6_user_test_cases/1_approved.png)
  - [Exceed the maximum amount user story](docs/6_user_test_cases/2_exceed_terminal.png)
  - [Insufficient fund user story](docs/6_user_test_cases/3_insufficient_funds.png)
  - [Expired card user story](docs/6_user_test_cases/4_card_expired.png)
  - [Stolen card user story](docs/6_user_test_cases/5_stolen_card.png)
  - 🎥 [User Stories Video](docs/6_user_test_cases/vid_user_cases.mp4)
