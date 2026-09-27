#include <iostream>
#include <vector>

#include "User.h"
#include "PersonalInfo.h"
#include "Document.h"
#include "Contact.h"
#include "Note.h"
#include "FileManager.h"

using namespace std;

int main()
{
    User user;
    PersonalInfo info;

    vector<Document> documents;
    vector<Contact> contacts;
    vector<Note> notes;

    // LOAD PREVIOUSLY SAVED DATA
    FileManager::loadPersonalInfo(
        "personal_info.txt",
        info
    );

    FileManager::loadDocuments(
        "documents.txt",
        documents
    );

    FileManager::loadContacts(
        "contacts.txt",
        contacts
    );

    FileManager::loadNotes(
        "notes.txt",
        notes
    );

    // PROGRAM TITLE
    cout << "==================================" << endl;
    cout << "     PERSONAL DIGITAL LOCKER" << endl;
    cout << "==================================" << endl;

    // REGISTRATION / LOGIN
    if (!user.isRegistered())
    {
        cout << "\nNo registered user found." << endl;

        user.registerUser();
    }

    cout << "\nPlease login to continue." << endl;

    // LOGIN
    if (!user.login())
    {
        cout << "\nLogin failed. Exiting..." << endl;
        return 0;
    }

    int choice;

    // DASHBOARD
    do
    {
        cout << "\n==================================" << endl;
        cout << "            DASHBOARD" << endl;
        cout << "==================================" << endl;

        cout << "1. Personal Information" << endl;
        cout << "2. Documents" << endl;
        cout << "3. Contacts" << endl;
        cout << "4. Notes" << endl;
        cout << "5. Search" << endl;
        cout << "6. Update Record" << endl;
        cout << "7. Delete Record" << endl;
        cout << "8. Logout" << endl;
        cout << "9. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        // PERSONAL INFORMATION
        case 1:
        {
            int personalChoice;

            do
            {
                cout << "\n--- Personal Information ---" << endl;

                cout << "1. Add Information" << endl;
                cout << "2. View Information" << endl;
                cout << "3. Update Information" << endl;
                cout << "4. Back" << endl;

                cout << "\nEnter your choice: ";
                cin >> personalChoice;

                switch (personalChoice)
                {
                case 1:
                    info.input();
                    break;

                case 2:
                    info.display();
                    break;

                case 3:
                    info.update();
                    break;

                case 4:
                    cout << "\nReturning to Dashboard..." << endl;
                    break;

                default:
                    cout << "\nInvalid choice!" << endl;
                }

            } while (personalChoice != 4);

            break;
        }

        // DOCUMENTS
        case 2:
        {
            int documentChoice;

            do
            {
                cout << "\n--- Documents ---" << endl;

                cout << "1. Add Document" << endl;
                cout << "2. View Documents" << endl;
                cout << "3. Back" << endl;

                cout << "\nEnter your choice: ";
                cin >> documentChoice;

                switch (documentChoice)
                {
                case 1:
                {
                    int id;
                    string title;
                    string type;
                    string number;
                    string description;

                    cout << "\n--- Add Document ---" << endl;

                    cout << "Enter document ID: ";
                    cin >> id;

                    cout << "Enter document title: ";
                    getline(cin >> ws, title);

                    cout << "Enter document type: ";
                    getline(cin, type);

                    cout << "Enter document number: ";
                    getline(cin, number);

                    cout << "Enter description: ";
                    getline(cin, description);

                    documents.emplace_back(
                        id,
                        title,
                        type,
                        number,
                        description
                    );

                    cout << "\nDocument added successfully!" << endl;

                    break;
                }

                case 2:
                {
                    if (documents.empty())
                    {
                        cout << "\nNo documents available." << endl;
                    }
                    else
                    {
                        cout << "\n--- Stored Documents ---" << endl;

                        for (Document &doc : documents)
                        {
                            doc.display();
                        }
                    }

                    break;
                }

                case 3:
                    cout << "\nReturning to Dashboard..." << endl;
                    break;

                default:
                    cout << "\nInvalid choice!" << endl;
                }

            } while (documentChoice != 3);

            break;
        }

        // CONTACTS
        case 3:
        {
            int contactChoice;

            do
            {
                cout << "\n--- Contacts ---" << endl;

                cout << "1. Add Contact" << endl;
                cout << "2. View Contacts" << endl;
                cout << "3. Back" << endl;

                cout << "\nEnter your choice: ";
                cin >> contactChoice;

                switch (contactChoice)
                {
                case 1:
                {
                    int id;
                    string title;
                    string phone;
                    string relationship;

                    cout << "\n--- Add Contact ---" << endl;

                    cout << "Enter contact ID: ";
                    cin >> id;

                    cout << "Enter contact name: ";
                    getline(cin >> ws, title);

                    cout << "Enter phone number: ";
                    getline(cin, phone);

                    cout << "Enter relationship: ";
                    getline(cin, relationship);

                    contacts.emplace_back(
                        id,
                        title,
                        phone,
                        relationship
                    );

                    cout << "\nContact added successfully!" << endl;

                    break;
                }

                case 2:
                {
                    if (contacts.empty())
                    {
                        cout << "\nNo contacts available." << endl;
                    }
                    else
                    {
                        cout << "\n--- Stored Contacts ---" << endl;

                        for (Contact &contact : contacts)
                        {
                            contact.display();
                        }
                    }

                    break;
                }

                case 3:
                    cout << "\nReturning to Dashboard..." << endl;
                    break;

                default:
                    cout << "\nInvalid choice!" << endl;
                }

            } while (contactChoice != 3);

            break;
        }

        // NOTES
        case 4:
        {
            int noteChoice;

            do
            {
                cout << "\n--- Notes ---" << endl;

                cout << "1. Add Note" << endl;
                cout << "2. View Notes" << endl;
                cout << "3. Back" << endl;

                cout << "\nEnter your choice: ";
                cin >> noteChoice;

                switch (noteChoice)
                {
                case 1:
                {
                    int id;
                    string title;
                    string content;

                    cout << "\n--- Add Note ---" << endl;

                    cout << "Enter note ID: ";
                    cin >> id;

                    cout << "Enter note title: ";
                    getline(cin >> ws, title);

                    cout << "Enter note content: ";
                    getline(cin, content);

                    notes.emplace_back(
                        id,
                        title,
                        content
                    );

                    cout << "\nNote added successfully!" << endl;

                    break;
                }

                case 2:
                {
                    if (notes.empty())
                    {
                        cout << "\nNo notes available." << endl;
                    }
                    else
                    {
                        cout << "\n--- Stored Notes ---" << endl;

                        for (Note &note : notes)
                        {
                            note.display();
                        }
                    }

                    break;
                }

                case 3:
                    cout << "\nReturning to Dashboard..." << endl;
                    break;

                default:
                    cout << "\nInvalid choice!" << endl;
                }

            } while (noteChoice != 3);

            break;
        }

        // SEARCH
        case 5:
        {
            int searchChoice;
            string searchTitle;

            cout << "\n--- Search ---" << endl;

            cout << "1. Search Documents" << endl;
            cout << "2. Search Contacts" << endl;
            cout << "3. Search Notes" << endl;

            cout << "\nEnter your choice: ";
            cin >> searchChoice;

            if (searchChoice < 1 || searchChoice > 3)
            {
                cout << "\nInvalid search choice!" << endl;
                break;
            }

            cout << "Enter title/name to search: ";
            getline(cin >> ws, searchTitle);

            bool found = false;

            switch (searchChoice)
            {
            case 1:
                for (Document &doc : documents)
                {
                    if (doc.search(searchTitle))
                    {
                        doc.display();
                        found = true;
                    }
                }

                if (!found)
                {
                    cout << "\nDocument not found." << endl;
                }

                break;

            case 2:
                for (Contact &contact : contacts)
                {
                    if (contact.search(searchTitle))
                    {
                        contact.display();
                        found = true;
                    }
                }

                if (!found)
                {
                    cout << "\nContact not found." << endl;
                }

                break;

            case 3:
                for (Note &note : notes)
                {
                    if (note.search(searchTitle))
                    {
                        note.display();
                        found = true;
                    }
                }

                if (!found)
                {
                    cout << "\nNote not found." << endl;
                }

                break;
            }

            break;
        }

        // UPDATE
        case 6:
        {
            int updateChoice;
            int id;
            bool found = false;

            cout << "\n--- Update Record ---" << endl;

            cout << "1. Update Document" << endl;
            cout << "2. Update Contact" << endl;
            cout << "3. Update Note" << endl;

            cout << "\nEnter your choice: ";
            cin >> updateChoice;

            if (updateChoice < 1 || updateChoice > 3)
            {
                cout << "\nInvalid update choice!" << endl;
                break;
            }

            cout << "Enter record ID: ";
            cin >> id;

            switch (updateChoice)
            {
            case 1:
                for (Document &doc : documents)
                {
                    if (doc.getRecordId() == id)
                    {
                        doc.update();
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "\nDocument not found." << endl;
                }

                break;

            case 2:
                for (Contact &contact : contacts)
                {
                    if (contact.getRecordId() == id)
                    {
                        contact.update();
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "\nContact not found." << endl;
                }

                break;

            case 3:
                for (Note &note : notes)
                {
                    if (note.getRecordId() == id)
                    {
                        note.update();
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "\nNote not found." << endl;
                }

                break;
            }

            break;
        }

        // DELETE
        case 7:
        {
            int deleteChoice;
            int id;
            bool found = false;

            cout << "\n--- Delete Record ---" << endl;

            cout << "1. Delete Document" << endl;
            cout << "2. Delete Contact" << endl;
            cout << "3. Delete Note" << endl;

            cout << "\nEnter your choice: ";
            cin >> deleteChoice;

            if (deleteChoice < 1 || deleteChoice > 3)
            {
                cout << "\nInvalid delete choice!" << endl;
                break;
            }

            cout << "Enter record ID: ";
            cin >> id;

            switch (deleteChoice)
            {
            case 1:
                for (auto it = documents.begin();
                     it != documents.end();
                     ++it)
                {
                    if (it->getRecordId() == id)
                    {
                        documents.erase(it);
                        found = true;

                        cout << "\nDocument deleted successfully!"
                             << endl;

                        break;
                    }
                }

                if (!found)
                {
                    cout << "\nDocument not found." << endl;
                }

                break;

            case 2:
                for (auto it = contacts.begin();
                     it != contacts.end();
                     ++it)
                {
                    if (it->getRecordId() == id)
                    {
                        contacts.erase(it);
                        found = true;

                        cout << "\nContact deleted successfully!"
                             << endl;

                        break;
                    }
                }

                if (!found)
                {
                    cout << "\nContact not found." << endl;
                }

                break;

            case 3:
                for (auto it = notes.begin();
                     it != notes.end();
                     ++it)
                {
                    if (it->getRecordId() == id)
                    {
                        notes.erase(it);
                        found = true;

                        cout << "\nNote deleted successfully!"
                             << endl;

                        break;
                    }
                }

                if (!found)
                {
                    cout << "\nNote not found." << endl;
                }

                break;
            }

            break;
        }

        // LOGOUT
        case 8:
            user.logout();
            break;

        // EXIT
        case 9:
            cout << "\nExiting Personal Digital Locker..." << endl;
            break;

        default:
            cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 9 && choice != 8);

    // SAVE ALL DATA USING FILE MANAGER

    FileManager::savePersonalInfo(
        "personal_info.txt",
        info
    );

    FileManager::saveDocuments(
        "documents.txt",
        documents
    );

    FileManager::saveContacts(
        "contacts.txt",
        contacts
    );

    FileManager::saveNotes(
        "notes.txt",
        notes
    );

    cout << "\nData saved successfully!" << endl;
    cout << "Thank you for using Personal Digital Locker!" << endl;

    return 0;
}