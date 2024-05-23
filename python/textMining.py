from collections import OrderedDict, defaultdict


def main():
    text = '''South Korea has said it will ban a viral North Korean propaganda tune that extols Pyongyang's dictator Kim Jong Un as a 'friendly father' and 'great leader'.
Seoul's media regulator said the music video, which has become a hit on TikTok since its release in April, is a violation of the country's National Security Act.
'[The song] idolizes Kim Jong Un and praises and glorifies him,' Seoul's Korea Communications Standards Commission said in a statement on Monday.
The Security Act blocks access to the North's government websites and media, and penalises behaviours and speeches in favour of the regime.
Twenty-nine versions of the Friendly Father music video will be blocked, the commission said, but it did not elaborate on how that would be done. The decision was prompted by a request from South Korea's National Intelligence Service, it added.
“The video is typical content linked to psychological warfare against South Korea, as it was posted on a channel operated to connect with the outside world and is mainly focused on unilaterally idolising and glorifying Kim,” the regulator said."'''

    word_count = defaultdict(lambda: 0)
    # split by ' '
    for word in text.split():
        word_count[word] += 1  # use word as a key
    print(word_count)
    for i, v in OrderedDict(
        sorted(word_count.items(), key=lambda t: t[1], reverse=True)
    ).items():
        print(i, v)


if __name__ == "__main__":
    main()
