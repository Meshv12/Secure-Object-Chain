#include <bits/stdc++.h>
#include <openssl/sha.h>

using namespace std;

class Block
{
public:
    Block(int data, const string &prevHash);
    string getPrevHash() const;
    string getHash() const;
    int getData() const;
    void printBlock() const;

private:
    int blockdata;
    string prevhash;
    string hash;
    string calculateHash() const;
    static string toString(int data, const string &prevHash);
};

Block::Block(int data, const string &prevHash)
    : blockdata(data), prevhash(prevHash), hash(calculateHash()) {}

string Block::getPrevHash() const
{
    return prevhash;
}

string Block::getHash() const
{
    return hash;
}

int Block::getData() const
{
    return blockdata;
}

string Block::calculateHash() const
{
    string dataToHash = toString(blockdata, prevhash);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char *>(dataToHash.c_str()), dataToHash.size(), hash);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

string Block::toString(int data, const string &prevHash)
{
    return prevHash + to_string(data);
}

void Block::printBlock() const
{
    cout << "Block Data: " << blockdata << endl;
    cout << "Previous Hash: " << prevhash << endl;
    cout << "Hash: " << hash << endl;
}

class Blockchain
{
public:
    Blockchain();
    void addBlock(int data);
    void verifyChain() const;
    void alterNthBlock(int n, int newData);
    void hackChain();
    void printAllBlocks() const;

private:
    vector<Block> chain;
    bool hashCompare(const string &hash1, const string &hash2) const;
};

Blockchain::Blockchain()
{
    // Create the Starting block of chain
    chain.emplace_back(Block(0, "0"));
}

void Blockchain::addBlock(int data)
{
    string prevHash = chain.back().getHash();
    chain.emplace_back(Block(data, prevHash));
}

void Blockchain::verifyChain() const
{
    for (size_t i = 1; i < chain.size(); ++i)
    {
        const Block &prevBlock = chain[i - 1];
        const Block &currBlock = chain[i];

        cout << "Block " << i << ": [" << currBlock.getData() << "] ";
        cout << "Previous Hash: " << prevBlock.getHash();
        cout << " - Current Block's Previous Hash: " << currBlock.getPrevHash();

        if (hashCompare(prevBlock.getHash(), currBlock.getPrevHash()))
            cout << " Verified" << endl;
        else
            cout << " Verification Failed" << endl;
    }
}

void Blockchain::alterNthBlock(int n, int newData)
{
    if (n < 0 || n >= chain.size())
    {
        cout << "Nth block does not exist" << endl;
        return;
    }

    Block &block = chain[n];
    cout << "Before alteration:" << endl;
    block.printBlock();

    chain[n] = Block(newData, (n == 0) ? "0" : chain[n - 1].getHash());

    cout << "After alteration:" << endl;
    chain[n].printBlock();
}

void Blockchain::hackChain()
{
    for (size_t i = 1; i < chain.size(); ++i)
    {
        const Block &prevBlock = chain[i - 1];
        Block &currBlock = chain[i];

        if (!hashCompare(prevBlock.getHash(), currBlock.getPrevHash()))
        {
            currBlock = Block(currBlock.getData(), prevBlock.getHash());
        }
    }
}

void Blockchain::printAllBlocks() const
{
    for (const Block &block : chain)
    {
        block.printBlock();
        cout << endl;
    }
}

bool Blockchain::hashCompare(const string &hash1, const string &hash2) const
{
    return hash1 == hash2;
}

int main()
{
    Blockchain blockchain;

    int choice, data, blockIndex;
    while (true)
    {
        cout << "1) Add Block" << endl;
        cout << "2) Verify Chain" << endl;
        cout << "3) Alter Nth Block" << endl;
        cout << "4) Print All Blocks" << endl;
        cout << "5) Hack Chain" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            blockchain.addBlock(data);
            break;
        case 2:
            blockchain.verifyChain();
            break;
        case 3:
            cout << "Which block to alter?: ";
            cin >> blockIndex;
            cout << "Enter new value: ";
            cin >> data;
            blockchain.alterNthBlock(blockIndex, data);
            break;
        case 4:
            blockchain.printAllBlocks();
            break;
        case 5:
            blockchain.hackChain();
            break;
        default:
            cout << "Wrong choice!" << endl;
            break;
        }
    }

    return 0;
}