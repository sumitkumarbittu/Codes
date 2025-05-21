class LZWTrieCompressor:
    def __init__(self):
        self.reset_dictionary()
    
    def reset_dictionary(self):
        # Initialize with single-character strings (0-255)
        self.root = {}
        self.next_code = 256
        for i in range(256):
            self.root[chr(i)] = {'code': i, 'children': {}}
    
    def compress(self, data):
        self.reset_dictionary()
        compressed = []
        w = ""
        
        for c in data:
            wc = w + c
            if self._in_trie(wc):
                w = wc
            else:
                # Output code for w
                compressed.append(self._get_code(w))
                # Add wc to dictionary
                self._add_to_trie(wc)
                w = c
        
        if w:
            compressed.append(self._get_code(w))
        
        return compressed
    
    def decompress(self, compressed):
        # Initialize dictionary with single-character strings
        dictionary = {i: chr(i) for i in range(256)}
        next_code = 256
        
        decompressed = []
        w = chr(compressed[0])
        decompressed.append(w)
        
        for code in compressed[1:]:
            if code in dictionary:
                entry = dictionary[code]
            elif code == next_code:
                entry = w + w[0]
            else:
                raise ValueError("Invalid compressed code")
            
            decompressed.append(entry)
            
            # Add to dictionary
            dictionary[next_code] = w + entry[0]
            next_code += 1
            
            w = entry
        
        return ''.join(decompressed)
    
    def _in_trie(self, s):
        node = self.root
        for c in s:
            if c not in node:
                return False
            node = node[c]['children']
        return True
    
    def _get_code(self, s):
        node = self.root
        for c in s[:-1]:
            node = node[c]['children']
        return node[s[-1]]['code']
    
    def _add_to_trie(self, s):
        node = self.root
        for c in s[:-1]:
            node = node[c]['children']
        node[s[-1]] = {'code': self.next_code, 'children': {}}
        self.next_code += 1


# Example usage
if __name__ == "__main__":
    lzw = LZWTrieCompressor()
    
    #original = "TOBEORNOTTOBEORTOBEORNOT"
    original = "TOBEOHIJIERHNINGIERJNIGRRNOTTOBEORTOBEORNOT"
    print("Original:", original)
    
    compressed = lzw.compress(original)
    print("Compressed:", compressed)
    
    decompressed = lzw.decompress(compressed)
    print("Decompressed:", decompressed)
    
    print("Original == Decompressed:", original == decompressed)