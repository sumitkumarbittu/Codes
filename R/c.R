url <- "https://raw.githubusercontent.com/fivethirtyeight/data/master/non-voters/nonvoters_data.csv"

voters <- read.csv(url)

nrow(voters)

ncol(voters)

View(voters)

voters$voter_category 
